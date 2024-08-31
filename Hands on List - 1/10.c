/* 
   Name : 10.c
   Author: Siddhesh Dare
   Description :10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
                    bytes (use lseek) and write again 10 bytes.
                    a. check the return value of lseek
                    b. open the file with od and check the empty spaces in between the data.
   Date :  30 Aug
*/


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int fd;
    char buf[10] = "abcdefghi";
    fd = open("file10.txt",O_CREAT|O_RDWR);
    if(fd<0) perror("Error ");
    write(fd,buf,10);
    printf("Written 10 bytes\n");
    lseek(fd,10,SEEK_CUR);
    printf("Moved file ptr by 10 bytes\n");
    write(fd,buf,10);
    printf("Again written 10 bytes\n");
    int r = lseek(fd,0,SEEK_CUR);
    printf("Return value of lseek is: %d\n",r);
}


/*
Output :
Written 10 bytes
Moved file ptr by 10 bytes
Again written 10 bytes
Return value of lseek is: 30
sid@sid-Inspiron-3505:~/List1$ od -c file10.txt
0000000   a   b   c   d   e   f   g   h   i  \0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   a   b   c   d   e   f   g   h   i  \0
0000036
*/