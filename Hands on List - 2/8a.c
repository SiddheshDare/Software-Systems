/* 
   Name : 8a.c
   Author: Siddhesh Dare
   Description :8. Write a separate program using signal system call to catch the following signals.
                   a. SIGSEGV

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void handler(int sig){
    printf("Caught SIGSEGV no. %d\n",sig);
    exit(0);
}
int main(){
    signal(SIGSEGV,handler);
    printf("Catching SIGSEGV\n");
    int *ptr = NULL;
    *ptr = 42;
    return 0;
}


/*
Output:
Catching SIGSEGV
Caught SIGSEGV no. 11
*/