/*
   Name : 29.c
   Author: Siddhesh Dare
   Description :29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
                    SCHED_RR).
   Date :  30 Aug
*/


#include<stdio.h>
#include<sched.h>
#include<unistd.h>
int main(){
    struct sched_param sp;
    pid_t q;
    q = getpid();
    int policyold =  sched_getscheduler(q);
    switch (policyold)
    {
    case SCHED_FIFO:
        printf("Current policy is FIFO\n");
        break;
    case SCHED_RR:
        printf("Current policy is RR\n");
        break;
    case SCHED_OTHER:
        printf("Current policy is OTHER\n");
        break;
    default:
        perror("Error while getting current policy\n");
        break;
    }
    sp.sched_priority = 5;
    sched_setscheduler(0,SCHED_RR,&sp);
    int policynew = sched_getscheduler(0);
    switch(policynew){
        case SCHED_FIFO:
        printf("New policy is FIFO\n");
        break;
        case SCHED_RR:
        printf("New policy is RR\n");
        break;
        case SCHED_OTHER:
        printf("New policy is OTHER\n");
        break;
    }
    return 0;
}


/*
Output :
sid@sid-Inspiron-3505:~/List1$ sudo ./a.out
Current policy is OTHER
New policy is RR
*/