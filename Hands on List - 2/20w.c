/* 
   Name : 20w.c
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
    fd = open("myfifo",O_WRONLY);
    printf("Enter the text: ");
    scanf("%[^\n]",buf);
    write(fd,buf,sizeof(buf));
}


/*
Output:
Enter the text: Hello
*/