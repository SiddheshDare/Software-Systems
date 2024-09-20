/* 
   Name : 15.c
   Author: Siddhesh Dare
   Description :15. Write a simple program to send some data from parent to the child process.


   Date :  10 Sep
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    int fd[2],s;
    char buf[100];
    __pid_t p;
    pipe(fd);
    p = fork();
    if(p>0){
        close(fd[0]);
        printf("Parent is sending data\n");
        scanf("%[^\n]",buf);
        write(fd[1],buf,sizeof(buf));
    }
    else
    {
        sleep(5);
        close(fd[1]);
        read(fd[0],buf,sizeof(buf));
        printf("Child received data\n");
        printf("Message from parent: %s\n",buf);
    }
    wait(0);
}


/*
Output:
Parent is sending data
Hello child
Child received data
Message from parent: Hello child
*/