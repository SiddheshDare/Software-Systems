#ifndef LOAN_RECORDS
#define LOAN_RECORDS

struct Loan
{
    int id;                  // Loan application ID
    int customer_id;        // Customer ID applying for the loan
    long int amount;           // Loan amount requested
    char status[20];        // Status of the loan application (Pending, Approved, Rejected)
    int assigned_employee_id; // ID of the employee assigned to the application
};

#endif 
