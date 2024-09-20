/* 
   Name : 22.c
   Author: Siddhesh Dare
   Description :22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
                    system call with FIFO.


   Date :  17 Sep
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
int main(){
    int fd,retval;
    char buf[100];
    fd_set rfds;
    struct timeval tv;
    fd = open("myfifo",O_RDONLY);
    FD_ZERO(&rfds);
    FD_SET(fd,&rfds);
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    retval = select(fd+1,&rfds,NULL,NULL,&tv);
    if(retval){
        printf("Data is available within 5 seconds.\n");
        read(fd,buf,sizeof(buf));
    printf("The text from FIFO: %s\n",buf);
    }
    else{
        printf("No Data available within 5 seconds.\n");
        exit(0);
    }
    
}


/*
Output:
Data is available within 5 seconds.
The text from FIFO: Hello
*/