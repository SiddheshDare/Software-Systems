/* 
   Name : 17b.c
   Author: Siddhesh Dare
   Description :17. Write a program to execute ls -l | wc.
                    b. use dup2
                    


   Date :  17 Sep
*/


#include<stdio.h>
#include<unistd.h>
int main(){
    int fd[2];
    pipe(fd);
    if(!fork()){
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls","ls","-l",NULL);
    }
    else{
        close(fd[1]);
        dup2(fd[0],0);
        execlp("wc","wc",NULL);
    }
}


/*
Output:
     67     594    3030
*/