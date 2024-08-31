/* 
   Name : 8.c
   Author: Siddhesh Dare
   Description :8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
                   Close the file when end of file is reached.
   Date :   30 Aug
*/


#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE* fd;
    char buf[100];
    fd = fopen("read.txt","r");
    if(fd<0) perror("Error ");
    while(fgets(buf,sizeof(buf),fd)){
        printf("%s",buf);
    }
    fclose(fd);
}


/*
Output:
Hello World!
How are you ?
I am fine.
What about you ?
I am also fine.
Ok Bye.
*/