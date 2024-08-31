/* 
   Name : 6.c
   Author: Siddhesh Dare
   Description :6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
   Date :  30 Aug
*/


#include<stdio.h>
#include<unistd.h>
int main(){
    char buf[20];
    int s = read(0,buf,20);
    write(1,buf,s);
    return 0;
}


/*
Output :
Hello World !
Hello World !
*/