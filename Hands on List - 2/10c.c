/* 
   Name : 10c.c
   Author: Siddhesh Dare
   Description :10. Write a separate program using sigaction system call to catch the following signals.
                    c. SIGFPE
   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void handle(int sig){
    printf("Caught SIGFPE no. %d\n",sig);
    exit(0);
}
int main(){
    struct sigaction s;
    s.sa_handler = handle;
    s.sa_flags = 0;
    printf("Catching SIGFPE\n");
    sigaction(SIGFPE,&s,NULL);
    int a = 20, b = 0;
    int c = a/b;
    return 0;
}


/*
Output:
Catching SIGFPE
Caught SIGFPE no. 8
*/