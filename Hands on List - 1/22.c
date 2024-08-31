/*
   Name : 22.c
   Author: Siddhesh Dare
   Description :22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
                    parent processes. Check output of the file.
   Date :  30 Aug
*/


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd;
    fd = open("write.txt",O_WRONLY|O_CREAT,0700);
    pid_t q;
    q = fork();
    if (q == -1) {
        perror("fork");
        return 1;
    } else if (q == 0) {
        // Child process
        printf("Child process ID: %d\n", getpid());
        write(fd,"This is written by child process.\n",35);
    } else {
        // Parent process
        printf("Parent process ID: %d\n", getpid());
        write(fd,"This is written by parent process.\n",36);
    }

}


/*
Output: 
sid@sid-Inspiron-3505:~/List1$ ./a.out
Parent process ID: 12164
Child process ID: 12165
sid@sid-Inspiron-3505:~/List1$ cat write.txt
This is written by parent process.
This is written by child process.
*/