/* 
   Name : 24.c
   Author: Siddhesh Dare
   Description :24. Write a program to create a message queue and print the key and message queue id.

   Date :  17 Sep
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
int main(){
    int msgid;
    key_t key;
    key = ftok(".",'a');
    msgid = msgget(key,IPC_CREAT|IPC_EXCL|0744);
    printf("Key value = %d\n",key);
    printf("Message queue id = %d\n",msgid);
}


/*
Output:
Key value = 1627816116
Message queue id = 0
*/