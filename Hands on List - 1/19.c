/* 
   Name : 19.c
   Author: Siddhesh Dare
   Description :19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
   Date :  30 Aug
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__("rdtsc":"=A"(dst));
    return dst;
}
int main(){
    long long start,end,diff;
    start = rdtsc();
        getpid();
    end = rdtsc();
    diff = (end-start)/1.39;
    printf("Time taken is :%lluns\n",diff);
    return 0;
}


/*
Output :
Time taken is :17882ns
*/