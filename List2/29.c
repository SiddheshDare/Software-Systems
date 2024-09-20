/*
   Name : 29.c
   Author: Siddhesh Dare
   Description :29. Write a program to remove the message queue.

   Date :  18 Sep
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
    printf("Data is sent: %s\n",mq.message);
    msgctl(msgid,IPC_RMID,NULL);
    printf("Message queue removed.\n");
}


/*
Output:
Enter the message type: 10
Enter the message text: Hello
Data is sent: Hello
Message queue removed.
*/