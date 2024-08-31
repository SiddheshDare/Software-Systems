/*
   Name : 28.c
   Author: Siddhesh Dare
   Description :28. Write a program to get maximum and minimum real time priority.
   Date :  30 Aug
*/


#include<stdio.h>
#include<sched.h>
int main(){
    int max,min;
    max =  sched_get_priority_max(SCHED_RR);
    min = sched_get_priority_min(SCHED_RR);
    printf("Maximum priority is: %d\n",max);
    printf("Minimum priority is: %d\n",min);
    return 0;
}


/*
Output :
Maximum priority is: 99
Minimum priority is: 1
*/