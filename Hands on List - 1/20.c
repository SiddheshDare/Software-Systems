/*
   Name : 20.c
   Author: Siddhesh Dare
   Description :20. Find out the priority of your running program. Modify the priority with nice command.
   Date :  30 Aug
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
int main(){
    int p,q;
    p = getpriority(PRIO_PROCESS,0);
    printf("Current Priority :%d\n",p);
    nice(19);
    q = getpriority(PRIO_PROCESS,0);
    printf("New Priority :%d\n",q);
}


/*
Output :
Current Priority :0
New Priority :19
*/
