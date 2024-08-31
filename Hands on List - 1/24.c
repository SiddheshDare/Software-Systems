/*
   Name : 24.c
   Author: Siddhesh Dare
   Description :24. Write a program to create an orphan process.
   Date :  30 Aug
*/


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    pid_t q = fork();
    if(q==0){
        sleep(3);
        printf("I am child, my process ID is: %d\n",getpid());
        printf("My parent's process ID is: %d\n",getppid());
    }
    else {
        printf("I am parent, my process ID is: %d\n",getpid());
        printf("My child's process ID is: %d\n",q);
    }
}


/*
Output :
I am parent, my process ID is: 12523
My child's process ID is: 12524
sid@sid-Inspiron-3505:~/List1$ I am child, my process ID is: 12524
My parent's process ID is: 1926

*/