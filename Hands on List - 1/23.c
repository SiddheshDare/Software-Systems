/*
   Name : 23.c
   Author: Siddhesh Dare
   Description :23. Write a program to create a Zombie state of the running program.
   Date :  30 Aug
*/


#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    pid_t q = fork();
    if(q>0){
        sleep(10);
        printf("I am parent having PID: %d\n",getpid());
        printf("My child PID is: %d\n",q);
        } 
    else{
        printf("I am child having PID: %d\n",getpid());
        printf("My parent PID is: %d\n",getppid());
        printf("I am zombie process\n\n");
        } 
}


/*
Output :
sid@sid-Inspiron-3505:~/List1$ I am child having PID: 15711
My parent PID is: 15710
I am zombie process

I am parent having PID: 15710
My child PID is: 15711

*/