/* 
   Name : 11.c
   Author: Siddhesh Dare
   Description :11. Write a program to open a file, duplicate the file descriptor and append the file with both the
                    descriptors and check whether the file is updated properly or not.
                    a. use dup
                    b. use dup2
                    c. use fcntl
   Date :  30 Aug
*/


#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(){
    int fd,fd1,fd2,fd3;
    char buf[100];
    fd = open("file11.txt",O_RDWR | O_CREAT,0777);
    if(fd<0) perror("Error ");
    fd1 = dup(fd);
    if(fd1<0) perror("Error ");
    fd2 = dup2(fd,7);
    if(fd2<0) perror("Error ");
    fd3 = fcntl(fd,F_DUPFD,6);
    if(fd3<0) perror("Error ");
    write(fd,"Writing through fd\n",20);
    write(fd1,"Writing through fd1\n",21);
    write(fd2,"Writing through fd2\n",21);
    write(fd3,"Writing through fd3\n",21);
    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}


/*
Output :
Writing through fd
Writing through fd1
Writing through fd2
Writing through fd3
*/