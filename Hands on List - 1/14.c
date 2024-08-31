/* 
   Name : 14.c
   Author: Siddhesh Dare
   Description :14. Write a program to find the type of a file.
                    a. Input should be taken from command line.
                    b. program should be able to identify any type of a file.
   Date :  30 Aug
*/


#include<stdio.h>
#include <sys/types.h> 
#include <sys/stat.h>  
#include <unistd.h>    
#include <fcntl.h> 
int main(int argc,char *argv[]){
    struct stat s;
    int fd;
    if (argc != 2) printf("Pass the name of the file as the argument\n");
    fd = open(argv[1], O_RDONLY);
    fstat(fd, &s);
    if (S_ISREG(s.st_mode))
            write(STDOUT_FILENO, "Regular File\n", 13);

        else if (S_ISDIR(s.st_mode))
            write(STDOUT_FILENO, "Directory File\n", 15);

        else if (S_ISCHR(s.st_mode))
            write(STDOUT_FILENO, "Character File\n", 15);

        else if (S_ISBLK(s.st_mode))
            write(STDOUT_FILENO, "Block File\n", 11);

        else if (S_ISFIFO(s.st_mode))
            write(STDOUT_FILENO, "FIFO File\n", 10);

        else if (S_ISLNK(s.st_mode))
            write(STDOUT_FILENO, "Symbolic Link File\n", 19);

        else if (S_ISSOCK(s.st_mode))
            write(STDOUT_FILENO, "Socket\n", 7);

        else
            write(STDOUT_FILENO, "Error\n", 6);
}


/*
Output :
sid@sid-Inspiron-3505:~/List1$ ./a.out 7file1.txt
Regular File
*/