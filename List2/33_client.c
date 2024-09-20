/*
   Name : 33_client.c
   Author: Siddhesh Dare
   Description :33. Write a program to communicate between two machines using socket.

   Date :  19 Sep
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(){
    struct sockaddr_in serv;
    int sd;
    char buf[100];
    sd = socket(AF_UNIX,SOCK_STREAM,0);
    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5005);
    connect(sd,(void*)&serv,sizeof(serv));
    write(sd,"Hello Server\n",14);
    read(sd,buf,sizeof(buf));
    printf("Message from server: %s\n",buf);
}


/*
Output:
Message from server: ACK from Server
*/