/* 
   Name : 12.c
   Author: Siddhesh Dare
   Description :12. Write a program to find out the opening mode of a file. Use fcntl.
   Date :  30 Aug
*/


#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
    int fd,val;
    fd = open("file11.txt",O_RDONLY);
    if(fd<0) printf("Error ");
    val = fcntl(fd,F_GETFL);
    switch (O_ACCMODE & val)
                {
                case O_RDONLY:
                    printf("The file has been opened with the flags : O_RDONLY\n");
                    break;
                case O_WRONLY:
                    printf("The file has been opened with the flags : O_WRONLY\n");
                    break;
                case O_RDWR:
                    printf("The file has been opened with the flags : O_RDWR\n");
                    break;
                default:
                    printf("Error!");
                }
}


/*
Output :
The file has been opened with the flags : O_RDONLY
*/
