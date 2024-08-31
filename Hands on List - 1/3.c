/* 
   Name : 3.c
   Author: Siddhesh Dare
   Description :3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
   Date :   30 Aug          
*/


#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd;
    fd = creat("newfile",0744);
    if(fd<0) perror("Error ");
    printf("File descriptor : %d\n",fd);
}


/*
Output :
File descriptor : 3
*/