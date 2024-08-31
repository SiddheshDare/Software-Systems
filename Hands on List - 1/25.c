/*
   Name : 25.c
   Author: Siddhesh Dare
   Description :25. Write a program to create three child processes. The parent should wait for a particular child (use
                    waitpid system call).
   Date :  31 Aug
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int c1,c2,c3;
    printf("Parent PID: %d\n",getpid());
    if(((c1=fork())==0)){
        printf("Child1 PID: %d\n",getpid());
        return 0;
    }
    if(((c2=fork())==0)){
        printf("Child2 PID: %d\n",getpid());
        return 0;
    }
    if(((c3=fork())==0)){
        printf("Child3 PID: %d\n",getpid());
        return 0;
    }
    int w = waitpid(c3,NULL,0);
    if(w==-1){
        perror("Failure ");
        return 1;
    }
    printf("Parent waited for child with PID: %d\n",w);
}


/*
Output :
Parent PID: 17712
Child1 PID: 17713
Child2 PID: 17714
Child3 PID: 17715
Parent waited for child with PID: 17715
*/