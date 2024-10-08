/* 
   Name : 1a.c
   Author: Siddhesh Dare
   Description :1. Write a separate program (for each time domain) to set a interval timer in 10sec and
                   10micro second
                   a. ITIMER_REAL
   Date :  10 Sep
*/


#include <sys/time.h> 
#include <signal.h>   
#include <unistd.h>   
#include <stdio.h>    

void main(int argc, char *argv[])
{
    int timerStatus; 

    struct itimerval timer;

    if (argc != 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10ms timer\n");
        _exit(0);
    }

    if ((int)(*argv[1] - 48) == 1)
    {
        // Setting a interval timer for 10s
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    }
    else if ((int)(*argv[1] - 48) == 2)
    {
        // Setting a interval timer for 10ms
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    timerStatus = setitimer(ITIMER_REAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    while(1);
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./a.out 1
Alarm clock
sid@sid-Inspiron-3505:~/List2$ ./a.out 2
Alarm clock
*/