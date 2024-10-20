#ifndef MANAGER_FUNCTIONS
#define MANAGER_FUNCTIONS

// Semaphores are necessary joint account due the design choice I've made
#include <sys/ipc.h>
#include <sys/sem.h>


#include "../struct/account.h"
#include "../struct/customer.h"
#include "../struct/transaction.h"
#include "../functions/adminCredentials.h"
#include "../define.h"
#include "../functions/common.h"

struct Employee loggedInManager;
int semIdentifier;

// Function Prototypes =================================

bool manager_operation_handler(int connFD);
bool deactivate_cust_account(int connFD);
bool activate_cust_account(int connFD);
bool review_cust_feedback(int connFD);
bool get_loan_details(int connFD);
bool assign_loan_application(int connFD);
bool manager_change_password(int connFD);

// =====================================================

// Function Definition =================================

bool manager_operation_handler(int connFD)
{
    if (login_employee_manager_handler(3, connFD, &loggedInManager))
    {
        printf("Manager");
        ssize_t writeBytes, readBytes;            // Number of bytes read from / written to the client
        char readBuffer[1000], writeBuffer[1000]; // A buffer used for reading & writing to the client
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, MANAGER_LOGIN_SUCCESS);
        while (1)
        {
            strcat(writeBuffer, "\n");
            strcat(writeBuffer, MANAGER_MENU);
            writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
            if (writeBytes == -1)
            {
                perror("Error while writing ADMIN_MENU to client!");
                return false;
            }
            bzero(writeBuffer, sizeof(writeBuffer));

            readBytes = read(connFD, readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
            {
                perror("Error while reading client's choice for ADMIN_MENU");
                return false;
            }

            int choice = atoi(readBuffer);
            switch (choice)
            {
            case 1:
                activate_cust_account(connFD);
                break;
            case 2:
                deactivate_cust_account(connFD);
                break;
            case 3:
                get_loan_details(connFD);
                break;
            case 4: 
                assign_loan_application(connFD);
                break;
            case 5:
                review_feedback(connFD);
                break;
            case 6:
                manager_change_password(connFD);
                break;
            default:
                writeBytes = write(connFD, MANAGER_LOGOUT, strlen(MANAGER_LOGOUT));
                return false;
            }
        }
    }
    else
    {
        // MANAGER LOGIN FAILED
        return false;
    }
    return true;
}


bool deactivate_cust_account(int connFD)
{
    ssize_t readBytes, writeBytes;
    char readBuffer[1000], writeBuffer[1000];

    struct Account account;

    writeBytes = write(connFD, ADMIN_DEACT_ACCOUNT_NO, strlen(ADMIN_DEACT_ACCOUNT_NO));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_DEACT_ACCOUNT_NO to client!");
        return false;
    }

    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connFD, readBuffer, sizeof(readBuffer));
    if (readBytes == -1)
    {
        perror("Error reading account number response from the client!");
        return false;
    }

    int accountNumber = atoi(readBuffer);

    int accountFileDescriptor = open(ACCOUNT_FILE, O_RDONLY);
    if (accountFileDescriptor == -1)
    {
        // Account record doesn't exist
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, ACCOUNT_ID_DOESNT_EXIT);
        strcat(writeBuffer, "^");
        writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
        if (writeBytes == -1)
        {
            perror("Error while writing ACCOUNT_ID_DOESNT_EXIT message to client!");
            return false;
        }
        readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
        return false;
    }


    int offset = lseek(accountFileDescriptor, accountNumber * sizeof(struct Account), SEEK_SET);
    if (errno == EINVAL)
    {
        // Customer record doesn't exist
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, ACCOUNT_ID_DOESNT_EXIT);
        strcat(writeBuffer, "^");
        writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
        if (writeBytes == -1)
        {
            perror("Error while writing ACCOUNT_ID_DOESNT_EXIT message to client!");
            return false;
        }
        readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
        return false;
    }
    else if (offset == -1)
    {
        perror("Error while seeking to required account record!");
        return false;
    }

    struct flock lock = {F_RDLCK, SEEK_SET, offset, sizeof(struct Account), getpid()};
    int lockingStatus = fcntl(accountFileDescriptor, F_SETLKW, &lock);
    if (lockingStatus == -1)
    {
        perror("Error obtaining read lock on Account record!");
        return false;
    }

    readBytes = read(accountFileDescriptor, &account, sizeof(struct Account));
    if (readBytes == -1)
    {
        perror("Error while reading Account record from file!");
        return false;
    }

    lock.l_type = F_UNLCK;
    fcntl(accountFileDescriptor, F_SETLK, &lock);

    close(accountFileDescriptor);

    bzero(writeBuffer, sizeof(writeBuffer));
    if (account.balance == 0)
    {
        // No money, hence can close account
        account.active = false;
        accountFileDescriptor = open(ACCOUNT_FILE, O_WRONLY);
        if (accountFileDescriptor == -1)
        {
            perror("Error opening Account file in write mode!");
            return false;
        }

        offset = lseek(accountFileDescriptor, accountNumber * sizeof(struct Account), SEEK_SET);
        if (offset == -1)
        {
            perror("Error seeking to the Account!");
            return false;
        }

        lock.l_type = F_WRLCK;
        lock.l_start = offset;

        int lockingStatus = fcntl(accountFileDescriptor, F_SETLKW, &lock);
        if (lockingStatus == -1)
        {
            perror("Error obtaining write lock on the Account file!");
            return false;
        }

        writeBytes = write(accountFileDescriptor, &account, sizeof(struct Account));
        if (writeBytes == -1)
        {
            perror("Error deactivating account record!");
            return false;
        }

        lock.l_type = F_UNLCK;
        fcntl(accountFileDescriptor, F_SETLK, &lock);

        strcpy(writeBuffer, ADMIN_DEACT_ACCOUNT_SUCCESS);
    }
    else
        // Account has some money ask customer to withdraw it
        strcpy(writeBuffer, ADMIN_DEACT_ACCOUNT_FAILURE);
    writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
    if (writeBytes == -1)
    {
        perror("Error while writing final deactivate message to client!");
        return false;
    }
    readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read

    return true;
}


bool activate_cust_account(int connFD)
{
    ssize_t readBytes, writeBytes;
    char readBuffer[1000], writeBuffer[1000];

    struct Account account;

    writeBytes = write(connFD, ADMIN_ACT_ACCOUNT_NO, strlen(ADMIN_ACT_ACCOUNT_NO));
    if (writeBytes == -1)
    {
        perror("Error writing ADMIN_ACT_ACCOUNT_NO to client!");
        return false;
    }

    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connFD, readBuffer, sizeof(readBuffer));
    if (readBytes == -1)
    {
        perror("Error reading account number response from the client!");
        return false;
    }

    int accountNumber = atoi(readBuffer);

    int accountFileDescriptor = open(ACCOUNT_FILE, O_RDONLY);
    if (accountFileDescriptor == -1)
    {
        // Account record doesn't exist
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, ACCOUNT_ID_DOESNT_EXIT);
        strcat(writeBuffer, "^");
        writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
        if (writeBytes == -1)
        {
            perror("Error while writing ACCOUNT_ID_DOESNT_EXIT message to client!");
            return false;
        }
        readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
        return false;
    }


    int offset = lseek(accountFileDescriptor, accountNumber * sizeof(struct Account), SEEK_SET);
    if (errno == EINVAL)
    {
        // Customer record doesn't exist
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, ACCOUNT_ID_DOESNT_EXIT);
        strcat(writeBuffer, "^");
        writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
        if (writeBytes == -1)
        {
            perror("Error while writing ACCOUNT_ID_DOESNT_EXIT message to client!");
            return false;
        }
        readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
        return false;
    }
    else if (offset == -1)
    {
        perror("Error while seeking to required account record!");
        return false;
    }

    struct flock lock = {F_RDLCK, SEEK_SET, offset, sizeof(struct Account), getpid()};
    int lockingStatus = fcntl(accountFileDescriptor, F_SETLKW, &lock);
    if (lockingStatus == -1)
    {
        perror("Error obtaining read lock on Account record!");
        return false;
    }

    readBytes = read(accountFileDescriptor, &account, sizeof(struct Account));
    if (readBytes == -1)
    {
        perror("Error while reading Account record from file!");
        return false;
    }

    lock.l_type = F_UNLCK;
    fcntl(accountFileDescriptor, F_SETLK, &lock);

    close(accountFileDescriptor);

    bzero(writeBuffer, sizeof(writeBuffer));

    account.active = true;

    accountFileDescriptor = open(ACCOUNT_FILE, O_WRONLY);
    if (accountFileDescriptor == -1)
    {
        perror("Error opening Account file in write mode!");
        return false;
    }

    offset = lseek(accountFileDescriptor, accountNumber * sizeof(struct Account), SEEK_SET);
    if (offset == -1)
    {
        perror("Error seeking to the Account!");
        return false;
    }

    lock.l_type = F_WRLCK;
    lock.l_start = offset;

    lockingStatus = fcntl(accountFileDescriptor, F_SETLKW, &lock);
    if (lockingStatus == -1)
    {
        perror("Error obtaining write lock on the Account file!");
        return false;
    }

    writeBytes = write(accountFileDescriptor, &account, sizeof(struct Account));
    if (writeBytes == -1)
    {
        perror("Error activating account record!");
        return false;
    }

    lock.l_type = F_UNLCK;
    fcntl(accountFileDescriptor, F_SETLK, &lock);

    strcpy(writeBuffer, ADMIN_ACT_ACCOUNT_SUCCESS);
    writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
    if (writeBytes == -1)
    {
        perror("Error while writing final activate message to client!");
        return false;
    }
    readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read

    return true;
}


bool review_cust_feedback(int connFD){
    int fd;
    char buffer[1024],tempBuffer[1000];
    ssize_t bytes_read;

    // Open the feedback file in read mode
    fd = open(FEEDBACK_FILE, O_RDONLY);
    if (fd == -1) {
        perror("Error opening feedback file");
        return false;
    }
    bzero(buffer, sizeof(buffer));
    // Send feedback to the client
    while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        bzero(tempBuffer, sizeof(tempBuffer));
        tempBuffer[bytes_read] = '\0';  // Null-terminate the buffer


        // Write the content to the client via connFD
        if (strlen(buffer) == 0)
            strcpy(buffer, tempBuffer);
        else
            strcat(buffer, tempBuffer);
    }

    if (bytes_read == -1) {
        perror("Error reading feedback file");
    }

    // Close the feedback file
    close(fd);

    if (strlen(buffer) == 0)
            {
                write(connFD, "No feedback found", strlen("No feedback found"));
                return false;
            }
            else
            {
                strcat(buffer, "\nAll feedback records displayed.\n");
                bytes_read = write(connFD, buffer, strlen(buffer));
            }

    return true;

}

bool get_loan_details(int connFD){
    int loanFileDescriptor;
    ssize_t readBytes, writeBytes; 
    struct Loan loanRecord;
    char writeBuffer[1000],tempBuffer[1000];

    // Open the loan file in read-only mode
    loanFileDescriptor = open(LOAN_FILE, O_RDONLY);
    if (loanFileDescriptor == -1) {
        perror("Error while opening loan file!");
        return false;
    }
    bzero(writeBuffer,sizeof(writeBuffer));
    // Read all the loan records from the file and send them to the client (or print them)
    while ((readBytes = read(loanFileDescriptor, &loanRecord, sizeof(struct Loan))) > 0) {
        if (readBytes < sizeof(struct Loan)) {
            fprintf(stderr, "Incomplete read of loan record. Expected %ld, got %ld bytes\n", sizeof(struct Loan), readBytes);
            break;
        }

        // Clear the buffer
        bzero(tempBuffer, sizeof(tempBuffer));

        // Format the loan record into the buffer
        sprintf(tempBuffer, "Loan ID: %d\nCustomer ID: %d\nAmount: %ld\nStatus: %s\nAssigned Employee ID: %d\n\n", 
                loanRecord.id, loanRecord.customer_id, loanRecord.amount, loanRecord.status, loanRecord.assigned_employee_id);

        if (strlen(writeBuffer) == 0)
            strcpy(writeBuffer, tempBuffer);
        else
            strcat(writeBuffer, tempBuffer);
        
    }


    // Close the file descriptor after reading all loan records
    close(loanFileDescriptor);
    if (strlen(writeBuffer) == 0)
            {
                write(connFD, LOAN_NOT_FOUND, strlen(LOAN_NOT_FOUND));
                return false;
            }
            else
            {
                strcat(writeBuffer, "\nAll loan records displayed.\n");
                writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
            }


    return true;
}


bool assign_loan_application(int connFD){
    ssize_t readBytes, writeBytes;            // Number of bytes read from / written to the socket
    char readBuffer[1000], writeBuffer[1000]; // A buffer for reading from / writing to the socket
    char tempBuffer[1000];

    int loanID,employeeID;
    struct Loan loan;
    int loanFileDescriptor;

    writeBytes = write(connFD, GET_LOAN_ID, strlen(GET_LOAN_ID));
    if (writeBytes == -1)
    {
        perror("Error writing GET_LOAN_ID message to client!");
        return false;
    }

    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connFD, readBuffer, sizeof(readBuffer));
    if (readBytes == -1)
    {
        perror("Error reading loan id response from client!");
        return false;
    }

    loanID = atoi(readBuffer);


    bzero(writeBuffer,sizeof(writeBuffer));
    writeBytes = write(connFD, GET_EMP_ID, strlen(GET_EMP_ID));
    if (writeBytes == -1)
    {
        perror("Error writing GET_EMP_ID message to client!");
        return false;
    }

    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connFD, readBuffer, sizeof(readBuffer));
    if (readBytes == -1)
    {
        perror("Error reading employee id response from client!");
        return false;
    }

    employeeID=atoi(readBuffer);




    loanFileDescriptor = open(LOAN_FILE, O_RDONLY);
    if (loanFileDescriptor == -1)
    {
        // Loan record doesn't exist
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, LOAN_ID_DOESNT_EXIT);
        strcat(writeBuffer, "^");
        perror("Error opening loan file in loan_details!");
        writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
        if (writeBytes == -1)
        {
            perror("Error while writing LOAN_ID_DOESNT_EXIT message to client!");
            return false;
        }
        readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
        return false;
    }

    int offset = lseek(loanFileDescriptor, loanID * sizeof(struct Loan), SEEK_SET);
    if (offset == -1 && errno == EINVAL)
    {
        // Loan record doesn't exist
        bzero(writeBuffer, sizeof(writeBuffer));
        strcpy(writeBuffer, LOAN_ID_DOESNT_EXIT);
        strcat(writeBuffer, "^");
        perror("Error seeking to loan record in get_loan_details!");
        writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
        if (writeBytes == -1)
        {
            perror("Error while writing LOAN_ID_DOESNT_EXIT message to client!");
            return false;
        }
        readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
        return false;
    }
    else if (offset == -1)
    {
        perror("Error while seeking to required loan record!");
        return false;
    }

    struct flock lock = {F_RDLCK, SEEK_SET, offset, sizeof(struct Loan), getpid()};

    int lockingStatus = fcntl(loanFileDescriptor, F_SETLKW, &lock);
    if (lockingStatus == -1)
    {
        perror("Error obtaining read lock on loan record!");
        return false;
    }

    readBytes = read(loanFileDescriptor, &loan, sizeof(struct Loan));
    if (readBytes == -1)
    {
        perror("Error reading loan record from file!");
        return false;
    }

    lock.l_type = F_UNLCK;
    fcntl(loanFileDescriptor, F_SETLK, &lock);

    loan.assigned_employee_id=employeeID;

    bzero(writeBuffer, sizeof(writeBuffer));
    strcpy(writeBuffer,"The employee is succesfully assigned with loan details:\n");
    sprintf(writeBuffer, "\nAccount Details - \n\tLoan Id : %d\n\tAssigned Employee ID : %d", loan.id, loan.assigned_employee_id);

    strcat(writeBuffer, "\n^");

    loanFileDescriptor = open(LOAN_FILE, O_WRONLY);
    if (loanFileDescriptor == -1)
    {
        perror("Error while opening loan file");
        return false;
    }
    offset = lseek(loanFileDescriptor, loanID * sizeof(struct Loan), SEEK_SET);
    if (offset == -1)
    {
        perror("Error while seeking to required loan record!");
        return false;
    }

    lock.l_type = F_WRLCK;
    lock.l_start = offset;
    lockingStatus = fcntl(loanFileDescriptor, F_SETLKW, &lock);
    if (lockingStatus == -1)
    {
        perror("Error while obtaining write lock on loan record!");
        return false;
    }

    writeBytes = write(loanFileDescriptor, &loan, sizeof(struct Loan));
    if (writeBytes == -1)
    {
        perror("Error while writing update loan info into file");
    }

    lock.l_type = F_UNLCK;
    fcntl(loanFileDescriptor, F_SETLKW, &lock);


    writeBytes = write(connFD, writeBuffer, strlen(writeBuffer));
    readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read

    return true;
}


bool manager_change_password(int connFD)
{
    ssize_t readBytes, writeBytes;
    char readBuffer[1000], writeBuffer[1000], hashedPassword[1000];

    char newPassword[1000];

    // Lock the critical section
    // struct sembuf semOp = {0, -1, SEM_UNDO};
    // int semopStatus = semop(semIdentifier, &semOp, 1);
    // if (semopStatus == -1)
    // {
    //     perror("Error while locking critical section");
    //     return false;
    // }

    writeBytes = write(connFD, PASSWORD_CHANGE_OLD_PASS, strlen(PASSWORD_CHANGE_OLD_PASS));
    if (writeBytes == -1)
    {
        perror("Error writing PASSWORD_CHANGE_OLD_PASS message to client!");
        // unlock_critical_section(&semOp);
        return false;
    }

    bzero(readBuffer, sizeof(readBuffer));
    readBytes = read(connFD, readBuffer, sizeof(readBuffer));
    if (readBytes == -1)
    {
        perror("Error reading old password response from client");
        // unlock_critical_section(&semOp);
        return false;
    }

    if (strcmp(crypt(readBuffer, SALT_BAE), loggedInManager.password) == 0)
    {
        // Password matches with old password
        writeBytes = write(connFD, PASSWORD_CHANGE_NEW_PASS, strlen(PASSWORD_CHANGE_NEW_PASS));
        if (writeBytes == -1)
        {
            perror("Error writing PASSWORD_CHANGE_NEW_PASS message to client!");
            // unlock_critical_section(&semOp);
            return false;
        }
        bzero(readBuffer, sizeof(readBuffer));
        readBytes = read(connFD, readBuffer, sizeof(readBuffer));
        if (readBytes == -1)
        {
            perror("Error reading new password response from client");
            // unlock_critical_section(&semOp);
            return false;
        }

        strcpy(newPassword, crypt(readBuffer, SALT_BAE));

        writeBytes = write(connFD, PASSWORD_CHANGE_NEW_PASS_RE, strlen(PASSWORD_CHANGE_NEW_PASS_RE));
        if (writeBytes == -1)
        {
            perror("Error writing PASSWORD_CHANGE_NEW_PASS_RE message to client!");
            // unlock_critical_section(&semOp);
            return false;
        }
        bzero(readBuffer, sizeof(readBuffer));
        readBytes = read(connFD, readBuffer, sizeof(readBuffer));
        if (readBytes == -1)
        {
            perror("Error reading new password reenter response from client");
            // unlock_critical_section(&semOp);
            return false;
        }

        if (strcmp(crypt(readBuffer, SALT_BAE), newPassword) == 0)
        {
            // New & reentered passwords match

            strcpy(loggedInManager.password, newPassword);

            int managerFileDescriptor = open(EMPLOYEE_FILE, O_WRONLY);
            if (managerFileDescriptor == -1)
            {
                perror("Error opening manager file!");
                // unlock_critical_section(&semOp);
                return false;
            }

            off_t offset = lseek(managerFileDescriptor, loggedInManager.id * sizeof(struct Employee), SEEK_SET);
            if (offset == -1)
            {
                perror("Error seeking to the manager record!");
                // unlock_critical_section(&semOp);
                return false;
            }

            struct flock lock = {F_WRLCK, SEEK_SET, offset, sizeof(struct Employee), getpid()};
            int lockingStatus = fcntl(managerFileDescriptor, F_SETLKW, &lock);
            if (lockingStatus == -1)
            {
                perror("Error obtaining write lock on manager record!");
                // unlock_critical_section(&semOp);
                return false;
            }

            writeBytes = write(managerFileDescriptor, &loggedInManager, sizeof(struct Employee));
            if (writeBytes == -1)
            {
                perror("Error storing updated manager password into manager record!");
                // unlock_critical_section(&semOp);
                return false;
            }

            lock.l_type = F_UNLCK;
            lockingStatus = fcntl(managerFileDescriptor, F_SETLK, &lock);

            close(managerFileDescriptor);

            writeBytes = write(connFD, PASSWORD_CHANGE_SUCCESS, strlen(PASSWORD_CHANGE_SUCCESS));
            readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read

            // unlock_critical_section(&semOp);

            return true;
        }
        else
        {
            // New & reentered passwords don't match
            writeBytes = write(connFD, PASSWORD_CHANGE_NEW_PASS_INVALID, strlen(PASSWORD_CHANGE_NEW_PASS_INVALID));
            readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
        }
    }
    else
    {
        // Password doesn't match with old password
        writeBytes = write(connFD, PASSWORD_CHANGE_OLD_PASS_INVALID, strlen(PASSWORD_CHANGE_OLD_PASS_INVALID));
        readBytes = read(connFD, readBuffer, sizeof(readBuffer)); // Dummy read
    }

    // unlock_critical_section(&semOp);

    return false;
}

#endif