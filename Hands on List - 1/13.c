/* 
   Name : 13.c
   Author: Siddhesh Dare
   Description :13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
                    verify whether the data is available within 10 seconds or not (check in $man 2 select).
   Date :  30 Aug
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int retval;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);
    if (retval == -1) {
        perror("select()");
        return 1;
    } 
    else if (retval) {
        printf("Data is available now.\n");
    } 
    else {
        printf("No data within 10 seconds.\n");
    }
    return 0;
}


/*
Output :
sid@sid-Inspiron-3505:~/List1$ ./a.out
No data within 10 seconds.
sid@sid-Inspiron-3505:~/List1$ ./a.out
HI
Data is available now.
*/
