/* 
   Name : 4.c
   Author: Siddhesh Dare
   Description :4. Write a program to measure how much time is taken to execute 100 getppid ( )
                   system call. Use time stamp counter.
   Date :  10 Sep
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
        for(int i=1;i<=100;i++){
            getppid();
        }
    end = rdtsc();
    diff = (end-start)/1.39;
    printf("Time taken is :%llu ns\n",diff);
    return 0;
}


/*
Output :
Time taken is :120553 ns
*/