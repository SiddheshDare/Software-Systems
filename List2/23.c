/* 
   Name : 23.c
   Author: Siddhesh Dare
   Description :23. Write a program to print the maximum number of files can be opened within a process and
                    size of a pipe (circular buffer).


   Date :  18 Sep
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    printf("Maximum no. of files can be opened in a process: %ld\n",sysconf(_SC_OPEN_MAX));
    printf("Size of a pipe: %ld\n",pathconf(".",_PC_PIPE_BUF));
}


/*
Output:
Maximum no. of files can be opened in a process: 1048576
Size of a pipe: 4096
*/