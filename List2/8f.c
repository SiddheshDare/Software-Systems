/* 
   Name : 8f.c
   Author: Siddhesh Dare
   Description :8. Write a separate program using signal system call to catch the following signals.
                f. SIGVTALRM (use setitimer system call)

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
void handle(int sig){
    printf("Caught SIGVTALRM no. %d\n",sig);
    exit(0);
}
int main(){
    signal(SIGVTALRM,handle);
        printf("Catching SIGVTALRM\n");
        struct itimerval timer;
        timer.it_value.tv_sec = 1;
        timer.it_value.tv_usec = 0;
        timer.it_interval.tv_sec = 1;
        timer.it_interval.tv_usec = 0;
        setitimer(ITIMER_VIRTUAL,&timer,NULL);
        while(1){
            
        }
        
    return 0;
}


/*
Output:
Catching SIGVTALRM
Caught SIGVTALRM no. 26
*/