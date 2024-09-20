/* 
   Name : 14.c
   Author: Siddhesh Dare
   Description :14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
                    the monitor.


   Date :  10 Sep
*/


#include<stdio.h>
#include<unistd.h>
int main(){
    int fd[2];
    char buf[100];
    pipe(fd);
    int s = write(fd[1],"Hello\n",7);
    read(fd[0],buf,s);
    printf("From pipe %s\n",buf);
}


/*
Output:
From pipe Hello
*/