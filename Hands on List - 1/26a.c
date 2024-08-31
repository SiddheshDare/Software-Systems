/*
   Name : 26a.c
   Author: Siddhesh Dare
   Description :26. Write a program to execute an executable program.
                    a. use some executable program
   Date :  31 Aug
*/


#include<stdio.h>
#include<unistd.h>
int main(){
    char *argv[] = {"./Hello",NULL};
    printf("This program will execute another executable file ./Hello\n");
    printf("Output of ./Hello is :\n");
    execvp(argv[0],argv);
}


/*
Output :
This program will execute another executable file ./Hello
Output of ./Hello is :
This program prints Hello World! 5 times
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!
*/