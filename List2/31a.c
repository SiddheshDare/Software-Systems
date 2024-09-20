/*
   Name : 31a.c
   Author: Siddhesh Dare
   Description :31. Write a program to create a semaphore and initialize value to the semaphore.
                    a. create a binary semaphore

   Date :  19 Sep
*/


#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <unistd.h>    
#include <stdio.h> 
int main(){
    union semun
    {
        int val;
    }Sem;
    key_t key;
    int id;
    key = ftok(".",2);
    id = semget(key,1,IPC_CREAT|0744);
    Sem.val = 1;
    semctl(id,0,SETVAL,Sem);
    printf("Binary semaphore created\n");
}


/*
Output:
Binary semaphore created
*/