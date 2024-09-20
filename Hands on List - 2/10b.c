/* 
   Name : 10b.c
   Author: Siddhesh Dare
   Description :10. Write a separate program using sigaction system call to catch the following signals.
                    b. SIGINT
   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
void handle(int sig){
    printf("\nCaught SIGINT no. %d\n",sig);
    exit(0);
}
int main(){
    struct sigaction s;
    s.sa_handler = handle;
    s.sa_flags = 0;
    printf("Catching SIGINT\n");
    sigaction(SIGINT,&s,NULL);
    sleep(2);
    return 0;
}


/*
Output:
Catching SIGINT
^C
Caught SIGINT no. 2
*/