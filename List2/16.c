/* 
   Name : 16.c
   Author: Siddhesh Dare
   Description :16. Write a program to send and receive data from parent to child vice versa. Use two way
                    communication.


   Date :  17 Sep
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
    char buf[100],buf1[100];
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    if(!fork()){
        close(fd1[0]);
        printf("Enter message to parent: ");
        scanf("%[^\n]",buf);
        write(fd1[1],buf,sizeof(buf));
        close(fd2[1]);
        read(fd2[0],buf1,sizeof(buf1));
        printf("Message from parent: %s\n",buf1);
    }
    else{
        close(fd1[1]);
        read(fd1[0],buf,sizeof(buf));
        printf("Message from child: %s\n",buf);
        close(fd2[0]);
        printf("Enter message to child: ");
        scanf("%[^\n]",buf1);
        write(fd2[1],buf1,sizeof(buf1));
    }
}


/*
Output:
Enter message to parent: I am your child
Message from child: I am your child
Enter message to child: Hello child
Message from parent: Hello child
*/
