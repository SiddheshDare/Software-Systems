/* 
   Name : 8g.c
   Author: Siddhesh Dare
   Description :8. Write a separate program using signal system call to catch the following signals.
                   g. SIGPROF (use setitimer system call)
   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
void handle(int sig){
    printf("Caught SIGPROF no. %d\n",sig);
    exit(0);
}
int main(){
    signal(SIGPROF,handle);
        printf("Catching SIGPROF\n");
        struct itimerval timer;
        timer.it_value.tv_sec = 1;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        setitimer(ITIMER_PROF,&timer,NULL);
        sleep(3);
        while (1)
        {
               
        }
        
    return 0;
}


/*
Output:
Catching SIGPROF
Caught SIGPROF no. 27
*/