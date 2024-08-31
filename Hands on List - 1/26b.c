/*
   Name : 26b.c
   Author: Siddhesh Dare
   Description :26. Write a program to execute an executable program.
                    b. pass some input to an executable program. (for example execute an executable of $./a.out name)
   Date :  31 Aug
*/


#include<stdio.h>
#include<unistd.h>
int main(){
    char *argv[] = {"./Add",NULL};
    printf("This program will execute another executable file ./Add\n");
    execvp(argv[0],argv);
}


/*
Output :
This program will execute another executable file ./Add
Enter value of a : 2
Enter value of b : 5
Sum of two nos. is : 7
*/