/* 
   Name : 13a.c
   Author: Siddhesh Dare
   Description :13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                    will send the signal (using kill system call). Find out whether the first program is able to catch
                    the signal or not


   Date :  17 Sep
*/


#include <signal.h> 
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void customHandler()
{
    printf("Received SIGSTOP signal!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; 
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    signalStatus = signal(SIGSTOP, customHandler);
    printf("Putting the process to sleep for 15s\n");
    sleep(15);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");

    
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./a.out
Process ID: 4453
Putting the process to sleep for 15s

[1]+  Stopped                 ./a.out
*/