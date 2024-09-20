/* 
   Name : 8b.c
   Author: Siddhesh Dare
   Description :8. Write a separate program using signal system call to catch the following signals.
                   b. SIGINT

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void handle(int sig){
    printf("\nCaught SIGINT no. %d\n",sig);
    exit(0);
}
int main(){
    signal(SIGINT,handle);
    printf("Catching SIGINT\n");
    sleep(10);
    return 0;
}


/*
Output:
Catching SIGINT
^C
Caught SIGINT no. 2
*/