/*
   Name : 21.c
   Author: Siddhesh Dare
   Description :21. Write a program, call fork and print the parent and child process id.
   Date :  30 Aug
*/


#include <stdio.h>
#include <unistd.h>
#include<fcntl.h>
int main() {
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return 1;
    } 
    else if (child_pid == 0) {
        printf("Child process ID: %d\n", getpid());
    } 
    else {
        printf("Parent process ID: %d\n", getpid());
    }
    return 0;
}


/*
Output:
Parent process ID: 12099
Child process ID: 12100
*/
