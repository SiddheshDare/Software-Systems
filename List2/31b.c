/*
   Name : 31a.c
   Author: Siddhesh Dare
   Description :31. Write a program to create a semaphore and initialize value to the semaphore.
                    b. create a counting semaphore

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
    key = ftok(".",3);
    id = semget(key,3,IPC_CREAT|0744);
    Sem.val = 2;
    semctl(id,0,SETVAL,Sem);
    printf("Counting semaphore created\n");
}


/*
Output:
Counting semaphore created
*/