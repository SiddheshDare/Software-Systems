/* 
   Name : 8e.c
   Author: Siddhesh Dare
   Description :8. Write a separate program using signal system call to catch the following signals.
                e. SIGALRM (use setitimer system call)

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
void handle(int sig){
    printf("Caught SIGALRM no. %d\n",sig);
    exit(0);
}
int main(){
    signal(SIGALRM,handle);
        printf("Catching SIGALRM\n");
        struct itimerval timer;
        timer.it_value.tv_sec = 2;
        timer.it_value.tv_usec = 0;
        setitimer(ITIMER_REAL,&timer,NULL);
        sleep(5);
    return 0;
}


/*
Output:
Catching SIGALRM
Caught SIGALRM no. 14
*/
