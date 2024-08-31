/*
   Name : 30.c
   Author: Siddhesh Dare
   Description :30. Write a program to run a script at a specific time using a Daemon process.
   Date :  31 Aug
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>

void makeDaemon(time_t curr, time_t desired) {
        setsid();
        chdir("/");
        umask(0);
        printf("Childs pid is: %d and parents id is: %d\n", getpid(), getppid());
        printf("Daemon created and waits till specific time\n");
        while (difftime(desired, curr) > 0)
        {
                printf("Daemon running...\n");
                sleep(10);
                time(&curr);
        } 
        printf("Script ran at specific time\n");
        exit(0);
}

int main() {
        time_t curr, desired;
        struct tm *deadline;
        time(&curr); //getting current time
        deadline = localtime(&curr); // converting to local time

        deadline->tm_hour = 16; //specifying the time
        deadline->tm_min = 00;
        deadline->tm_sec = 0;
        desired = mktime(deadline);

        int value_fork=fork();
        if(!value_fork) {
                makeDaemon(curr, desired);
        }
        else {
                printf("Parent %d is going to exit\n", getpid());
        }
        return 0; 
}


/*
Output :
sid@sid-Inspiron-3505:~/List1$ ./a.out
Parent 16856 is going to exit
Childs pid is: 16857 and parents id is: 16856
Daemon created and waits till specific time
Daemon running...
sid@sid-Inspiron-3505:~/List1$ Daemon running...
Script ran at specific time

*/