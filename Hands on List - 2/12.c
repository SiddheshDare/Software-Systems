/* 
   Name : 12.c
   Author: Siddhesh Dare
   Description :12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
                    the parent process from the child process


   Date :  13 Sep
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main(){
    pid_t p = fork();
    if (p==0)
    {
        printf("I am child with PID : %d\n",getpid());
        printf("Sending SIGKILL to parent\n");
        kill(getppid(),SIGKILL);
        sleep(10);
        printf("Child : I am orphan\n");
    }
    else{
        printf("I am parent with PID : %d\n",getpid());
        sleep(5);
    }
    return 0;
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./a.out
I am parent with PID : 7017
I am child with PID : 7018
Sending SIGKILL to parent
Killed
sid@sid-Inspiron-3505:~/List2$ Child : I am orphan
*/