/* 
   Name : 8d.c
   Author: Siddhesh Dare
   Description :8. Write a separate program using signal system call to catch the following signals.
                   d. SIGALRM (use alarm system call)

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void handle(int sig){
    printf("Caught SIGALRM no. %d\n",sig);
    exit(0);
}
int main(){
    signal(SIGALRM,handle);
        printf("Catching SIGALRM\n");
        alarm(3);
        sleep(5);
    return 0;
}


/*
Output:
Catching SIGALRM
Caught SIGALRM no. 14
*/
