/* 
   Name : 10a.c
   Author: Siddhesh Dare
   Description :10. Write a separate program using sigaction system call to catch the following signals.
                    a. SIGSEGV

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void handle(int sig){
    printf("Caught SIGSEGV no. %d\n",sig);
    exit(0);
}
int main(){
    struct sigaction s;
    s.sa_handler = handle;
    s.sa_flags = 0;
    printf("Catching SIGSEGV\n");
    sigaction(SIGSEGV,&s,NULL);
    int *a = NULL;
    *a = 2;
    return 0;
}


/*
Output:
Catching SIGSEGV
Caught SIGSEGV no. 11
*/