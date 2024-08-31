/* 
   Name : 4.c
   Author: Siddhesh Dare
   Description :4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
   Date :  30 Aug
*/


#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd;
    fd = open("newfile",O_CREAT | O_EXCL,O_RDWR);
    printf("File descriptor : %d\n",fd);
    perror("Error ");
}


/*
Output :
File descriptor : -1
Error : File exists
*/