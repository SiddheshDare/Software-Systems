/*
   Name : 18.c
   Author: Siddhesh Dare
   Description :18. Write a program to perform Record locking.
                    a. Implement write lock
                    b. Implement read lock
                    Create three records in a file. Whenever you access a particular record, first lock it then modify/access
                    to avoid race condition.
   Date :  31 Aug
*/


#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
struct{
        int n,c;
    } data;
int main(){
    int fd,t;
    fd = open("database.txt",O_RDWR);
    printf("Select train no. (1,2,3) : ");
    scanf("%d",&t);
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (t-1)*sizeof(data);
    lock.l_len = sizeof(data);
    lock.l_pid = getpid();
    lseek(fd,(t-1)*sizeof(data),SEEK_SET);
    read(fd,&data,sizeof(data));
    printf("Before critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Ticket no. : %d\n",data.c);
    data.c++;
    lseek(fd,-1*sizeof(data),SEEK_CUR);
    write(fd,&data,sizeof(data));
    printf("To Book Ticket Press Enter \n");
    getchar();
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("Ticket booked successfully.\n");
}


/*
Output :
Select train no. (1,2,3) : 2
Before critical section
Ticket no. : 1
To Book Ticket Press Enter 

Ticket booked successfully.
*/