/* 
   Name : 7.c
   Author: Siddhesh Dare
   Description :7. Write a program to copy file1 into file2 ($cp file1 file2).
   Date :  30 Aug
*/


#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
   if(argc!=3) {printf("Error : Enter filename as argument\n"); exit(0);}
	int file1 = open(argv[1],O_RDONLY);
	if(file1<0){
        perror("Program ");
         exit(0);
         }
int file2 = open(argv[2],O_WRONLY | O_EXCL | O_CREAT,0600);

if(file2<0){
    perror("Program ");
 exit(0);
 }
char buf[1024];
int size;
while((size = read(file1,buf,sizeof(buf)))>0){
		write(file2,buf,size);
		close(file1);
		close(file2);
		return 0;}
}


/*
Output :
Content of 7file2
Content of this file will get copied to other file.
*/