/*
   Name : 17.c
   Author: Siddhesh Dare
   Description :17. Write a program to simulate online ticket reservation. Implement write lock
                    Write a program to open a file, store a ticket number and exit. Write a separate program, to
                    open the file, implement write lock, read the ticket number, increment the number and print
                    the new ticket number then close the file.
   Date :  31 Aug
*/


#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
    int fd;
    struct{
        int n;
    } data;
    struct flock lock;
    fd = open("ticket",O_RDWR);
    read(fd,&data,sizeof(data));
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Current ticket no. : %d\n",data.n);
    data.n++;
    lseek(fd,0L,SEEK_SET);
    printf("Inside critical section updating value...\n");
    printf("Updated ticket no. : %d\n",data.n);
    printf("Enter to unlock\n");
    write(fd,&data,sizeof(data));
    getchar();
    lock.l_type = F_UNLCK;
    printf("Unlocked\n");
    fcntl(fd,F_SETLK,&lock);
    printf("Finish\n");
    close(fd);
}


/*
Output :
Before critical section
Current ticket no. : 11
Inside critical section updating value...
Enter to unlock
Updated ticket no. : 12

Unlocked
Finish
*/