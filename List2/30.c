/*
   Name : 30.c
   Author: Siddhesh Dare
   Description :30. Write a program to create a shared memory.
                    a. write some data to the shared memory
                    b. attach with O_RDONLY and check whether you are able to overwrite.
                    c. detach the shared memory
                    d. remove the shared memory

   Date :  19 Sep
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#define SHM_SIZE 1024
int main(){
    key_t key = (".",10);
    char *data,*rdonlyptr;
    int shmid = shmget(key,SHM_SIZE,IPC_CREAT|0744);
    data = shmat(shmid,(void*)0,0);
    printf("Writing to shared memery: Hello\n");
    strncpy(data,"Hello",SHM_SIZE);
    rdonlyptr = shmat(shmid,(void*)0,SHM_RDONLY);
    //strncpy(rdonlyptr,"HI",SHM_SIZE);
    printf("Detaching shared memeory\n");
    shmdt(data);
    shmdt(rdonlyptr);
    printf("Deleting shared memeory\n");
    shmctl(shmid,IPC_RMID,NULL);
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./a.out
Writing to shared memery: Hello
Segmentation fault (core dumped)

sid@sid-Inspiron-3505:~/List2$ ./a.out
Writing to shared memery: Hello
Detaching shared memeory
Deleting shared memeory
*/