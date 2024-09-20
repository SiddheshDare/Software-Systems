/* 
   Name : 20r.c
   Author: Siddhesh Dare
   Description :20. Write two programs so that both can communicate by FIFO -Use one way communication.


   Date :  17 Sep
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd;
    char buf[100];
    fd = open("myfifo",O_RDONLY);
    read(fd,buf,sizeof(buf));
    printf("The text from FIFO: %s\n",buf);
}


/*
Output:
The text from FIFO: Hello
*/