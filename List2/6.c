/* 
   Name : 6.c
   Author: Siddhesh Dare
   Description :6. Write a simple program to create three threads.
   Date :  10 Sep
*/


#include <pthread.h> 
#include <stdio.h>   
#include<unistd.h> 

void *sampleFunction(void *data)
{
    printf("Running in thread: %lu\n", pthread_self());
}

void main()
{
    pthread_t threadOne, threadTwo, threadThree;

    // Create three threads
    if (pthread_create(&threadOne, NULL, sampleFunction, NULL))
        perror("Error while creating thread one");
    if (pthread_create(&threadTwo, NULL, sampleFunction, NULL))
        perror("Error while creating thread two");
    if (pthread_create(&threadThree, NULL, sampleFunction, NULL))
        perror("Error while creating thread three");


    // Wait for the threads to terminate and then terminate the main process
    pthread_exit(NULL);
}


/*
Output:
Running in thread: 133184020809408
Running in thread: 133184010323648
Running in thread: 133183999837888
*/