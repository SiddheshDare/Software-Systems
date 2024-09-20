/* 
   Name : 8c.c
   Author: Siddhesh Dare
   Description :8. Write a separate program using signal system call to catch the following signals.
                   c. SIGFPE

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void handle(int sig){
    printf("Caught SIGFPE no. %d\n",sig);
    exit(0);
}
int main(){
    signal(SIGFPE,handle);
    printf("Catching SIGFPE\n");
    int a = 1, b = 0;
    int c = a/b;
    return 0;
}


/*
Output:
Catching SIGFPE
Caught SIGFPE no. 8
*/