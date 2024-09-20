/* 
   Name : 17a.c
   Author: Siddhesh Dare
   Description :17. Write a program to execute ls -l | wc.
                    a. use dup
                    

   Date :  17 Sep
*/


#include<stdio.h>
#include<unistd.h>
int main(){
    int fd[2];
    pipe(fd);
    if(!fork()){
        close(1);
        close(fd[0]);
        dup(fd[1]);
        execlp("ls","ls","-l",NULL);
    }
    else{
        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc","wc",NULL);
    }
}


/*
Output:
     67     594    3030
*/