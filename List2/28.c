/* 
   Name : 28.c
   Author: Siddhesh Dare
   Description :28. Write a program to change the exiting message queue permission. (use msqid_ds structure)

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
    struct msqid_ds info;
    struct msg
    {
        long int mtype;
        char message[100];
    }mq;
    key = ftok(".",'b');
    msgid = msgget(key,IPC_CREAT|0666);
    msgctl(msgid,IPC_STAT,&info);
    printf("Access permission before: %o\n",info.msg_perm.mode);
    info.msg_perm.mode = 0606;
    msgctl(msgid,IPC_SET,&info);
    printf("Access permission after: %o\n",info.msg_perm.mode);
}


/*
Output:
Access permission before: 666
Access permission after: 606
*/