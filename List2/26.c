/* 
   Name : 26.c
   Author: Siddhesh Dare
   Description :26. Write a program to send messages to the message queue. Check $ipcs -q

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
    msgid = msgget(key,IPC_CREAT|0744);
    printf("Enter the message type: ");
    scanf("%ld",&mq.mtype);
    getchar();
    printf("Enter the message text: ");
    scanf("%[^\n]",mq.message);
    size = strlen(mq.message);
    msgsnd(msgid,&mq,size+1,0);
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./a.out
Enter the message type: 10
Enter the message text: Hello
sid@sid-Inspiron-3505:~/List2$ ./a.out
Enter the message type: 20
Enter the message text: How are you?
sid@sid-Inspiron-3505:~/List2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x610680b4 0          sid        744        19           2           
0x620680b4 1          sid        744        0            0           
*/