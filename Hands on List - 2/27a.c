/* 
   Name : 27a.c
   Author: Siddhesh Dare
   Description :27. Write a program to receive messages from the message queue.
                    a. with 0 as a flag


   Date :  17 Sep
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
int main(){
    int msgid,size;
    key_t key;
    struct msg
    {
        long int mtype;
        char message[100];
    }mq;
    key = ftok(".",'a');
    msgid = msgget(key,0);
    printf("Enter the message type to receive: ");
    scanf("%ld",&mq.mtype);
    msgrcv(msgid,&mq,sizeof(mq.message),mq.mtype,0);
    printf("Message type: %ld\n",mq.mtype);
    perror(" ");
    printf("Message text: %s\n",mq.message);
}


/*
Output:
Enter the message type to receive: 20
Message type: 20
 : Success
Message text: How are you?
*/