/*
   Name : 32a.c
   Author: Siddhesh Dare
   Description :32. Write a program to implement semaphore to protect any critical section.
                    a. rewrite the ticket number creation program using semaphore

   Date :  19 Sep
*/


#include<sys/ipc.h>   
#include<sys/sem.h>   
#include<sys/types.h> 
#include<fcntl.h>     
#include<unistd.h>    
#include<stdio.h>     

void main(){
    char *ticketFile = "ticket_file.txt";             
    int lseekOffset;
    int data;
      
    union semun{
        int val;               
        struct semid_ds *buf;  
        unsigned short *array; 
        struct seminfo *__buf; 
    } semvar; 

    int fd = open(ticketFile,O_CREAT|O_RDWR,S_IRWXU);
    int key = ftok(".",'d');
    int semid = semget(key,1,0);
    if(semid==-1){
        semid = semget(key,1,IPC_CREAT|0700); 
        semvar.val = 1; 
        int semctlflag = semctl(semid,0,SETVAL,semvar);
    }

    struct sembuf semOp; 
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Before critical section\n");
    getchar();
    
    semOp.sem_op = -1;
    int semopflag = semop(semid,&semOp,1);
    
    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");

    int read_bytes = read(fd,&data,sizeof(data));
    if(read_bytes==0)
      data = 1;
    else{
      data += 1;
      lseekOffset = lseek(fd,0,SEEK_SET);
    }

    int write_bytes = write(fd,&data,sizeof(data));

    printf("Your ticker number is: %d\n", data);
    printf("Press enter to exit from critical section!\n");
    getchar();
    
    
    semOp.sem_op = 1;
    semopflag = semop(semid,&semOp,1);
    close(fd);
}


/*
Output:
Before critical section

Obtained lock on critical section!
Now entering critical section!
Your ticker number is: 9
Press enter to exit from critical section!

*/