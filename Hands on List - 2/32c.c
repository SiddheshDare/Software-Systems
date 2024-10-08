/*
   Name : 32c.c
   Author: Siddhesh Dare
   Description :32. Write a program to implement semaphore to protect any critical section.
                    c. protect multiple pseudo resources ( may be two) using counting semaphore

   Date :  20 Sep
*/


#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <sys/types.h> 
#include <unistd.h>   
#include <fcntl.h> 
#include <stdio.h> 

void main(){
    char *filename = "sample.txt";
    char data[100]; // Sample data
      
    union semun{
        int val;           
    } semvar;

    int fd = open(filename,O_RDONLY);
    if(fd==-1){
      perror("Error while creating ticket file");
      return;
    }

    key_t key = ftok(".", 324);
    if(key==-1){
      perror("ftok returns");
      return;
    }

    int semid= semget(key,1,0);
    if(semid==-1){
      semid = semget(key,1,IPC_CREAT|0700);  
      if(semid==-1){
        perror("semget returns");
        return;
      }

      semvar.val = 2; // Set a counting semaphore
      int semctlflag = semctl(semid,0,SETVAL,semvar);
      if(semctlflag==-1){
        perror("semctl returns");
        return;
      }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    
    semOp.sem_op = -1;
    int semopflag = semop(semid,&semOp,1);
    if(semopflag==-1){
      perror("semop returns");
      return;
    }

    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");

    int read_bytes = read(fd,&data,sizeof(data));
    if(read_bytes==-1){
      perror("read returns");
      return;
    }
    else if(read_bytes==0)
       printf("No data exists!\n");
    else
       printf("Sample data:%s\n",data);
    
    printf("\nPress enter key to exit critical section!");
    getchar();

    
    semOp.sem_op = 1;
    semopflag = semop(semid,&semOp,1);
    if(semopflag==-1){
      perror("Error while operating on semaphore!");
      return;
    }

    close(fd);
}


/*
Output:
Press enter to obtain lock for the critical section!

Obtained lock on critical section!
Now entering critical section!
Sample data:This is a sample text.

Press enter key to exit critical section!
*/