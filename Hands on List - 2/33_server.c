/*
   Name : 33_server.c
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
    struct sockaddr_in serv, cli;
    int sd, nsd,sz;
    char buf[100];
    sd = socket(AF_UNIX,SOCK_STREAM,0);
    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5005);
    bind(sd,(void*)&serv,sizeof(serv));
    listen(sd,5);
    sz = sizeof(cli);
    nsd = accept(sd,(void*)&cli,&sz);
    read(nsd,buf,sizeof(buf));
    printf("Message from client: %s\n",buf);
    write(nsd,"ACK from Server\n",17);
}


/*
Output:
Message from client: Hello Server
*/