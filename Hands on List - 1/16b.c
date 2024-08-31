/*
   Name : 16b.c
   Author: Siddhesh Dare
   Description :16. Write a program to perform mandatory locking.
                b. Implement read lock
   Date :  31 Aug
*/


#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
    struct flock lock;
    int fd;
    fd = open("data",O_RDWR);
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Inside critical section reading...\n");
    printf("Enter to unlock\n");
    getchar();
    printf("Unlocked\n");
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("Finish\n");
}


/*
Output :
Before critical section
Inside critical section reading...
Enter to unlock

Unlocked
Finish
*/