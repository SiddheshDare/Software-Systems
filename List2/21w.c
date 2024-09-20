/* 
   Name : 21w.c
   Author: Siddhesh Dare
   Description :21. Write two programs so that both can communicate by FIFO -Use two way communications.


   Date :  17 Sep
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd,fd1;
    char buf[100],buf1[100];
    fd = open("myfifo",O_WRONLY);
    fd1 = open("myfifo1",O_RDONLY);
    printf("Enter the text: ");
    scanf("%[^\n]",buf);
    write(fd,buf,sizeof(buf));
    read(fd1,buf1,sizeof(buf1));
    printf("Text from myfifo: %s\n",buf1);

}


/*
Output:
Enter the text: Hello
Text from myfifo: How are you
*/