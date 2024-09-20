/* 
   Name : 13b.c
   Author: Siddhesh Dare
   Description :13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                    will send the signal (using kill system call). Find out whether the first program is able to catch
                    the signal or not


   Date :  17 Sep
*/


#include <sys/types.h> 
#include <signal.h>    
#include <unistd.h>    
#include <stdio.h>     
#include <stdlib.h> 

void main(int argc, char *argv[])
{
    int killStatus; // Determines success of `kill`
    pid_t pid;

    if (argc != 2)
    {
        printf("Pass the PID of the process to whom the SIGSTOP signal is to be sent!\n");
        _exit(0);
    }

    pid = atoi(argv[1]);

    killStatus = kill(pid, SIGSTOP);

    if(!killStatus) 
        printf("Successfully sent SIGSTOP signal to process (%d)\n", pid);
    else 
        perror("Error while sending signal!");
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./13b 4453
Successfully sent SIGSTOP signal to process (4453)
*/