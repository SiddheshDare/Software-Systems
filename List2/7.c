/* 
   Name : 7.c
   Author: Siddhesh Dare
   Description :7. Write a simple program to print the created thread ids.
   Date :  10 Sep
*/


#include <pthread.h> 
#include <stdio.h>   

void sampleFunction()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

void main()
{
    pthread_t threadID;

    // Create thread
    if(pthread_create(&threadID, NULL, (void *)sampleFunction, NULL))
        perror("Error while creating thread");

    pthread_exit(NULL);
}


/*
Output:
Running in thread with thread ID: 129877281867456
*/