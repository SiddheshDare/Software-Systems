/* 
   Name : 19d.c
   Author: Siddhesh Dare
   Description :19. Create a FIFO file by
                d. mknod system call

   Date :  20 Sep
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
int main() {
    mknod("myfifo19d", S_IFIFO | 0666, 0);
    printf("FIFO Created\n");
    return 0;
}


/*
Output:
FIFO Created
*/