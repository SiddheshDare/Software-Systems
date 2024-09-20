/* 
   Name : 25.c
   Author: Siddhesh Dare
   Description :25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                    a. access permission
                    b. uid, gid
                    c. time of last message sent and received
                    d. time of last change in the message queue
                    d. size of the queue
                    f. number of messages in the queue
                    g. maximum number of bytes allowed
                    h. pid of the msgsnd and msgrcv
   Date :  18 Sep
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<time.h>
int main(){
    int msgid;
    key_t key;
    struct msqid_ds info;
    key = ftok(".",'b');
    msgid = msgget(key,IPC_CREAT|0744);
    msgctl(msgid,IPC_STAT,&info);
    printf("Access permission: %o\n",info.msg_perm.mode);
    printf("UID: %d\n",info.msg_perm.uid);
    printf("GID: %d\n",info.msg_perm.gid);
    printf("Time of last message sent: %s\n",ctime(&info.msg_stime));
    printf("Time of last message received: %s\n",ctime(&info.msg_rtime));
    printf("Time of last change in the message queue: %s\n",ctime(&info.msg_ctime));
    printf("Size of the queue: %lu bytes\n",info.__msg_cbytes);
    printf("Number of messages in the queue: %lu\n",info.msg_qnum);
    printf("Maximum number of bytes allowed: %lu\n",info.msg_qbytes);
    printf("PID of last msgsnd: %d\n",info.msg_lspid);
    printf("PID of last msgrcv: %d\n",info.msg_lrpid);
    printf("Key value = %d\n",key);
    printf("Message queue id = %d\n",msgid);
}


/*
Output:
Access permission: 744
UID: 1000
GID: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970

Time of last message received: Thu Jan  1 05:30:00 1970

Time of last change in the message queue: Fri Sep 20 14:33:25 2024

Size of the queue: 0 bytes
Number of messages in the queue: 0
Maximum number of bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
Key value = 1644593332
Message queue id = 1
*/