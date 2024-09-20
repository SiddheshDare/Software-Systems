/* 
   Name : 19e.c
   Author: Siddhesh Dare
   Description :19. Create a FIFO file by
                   e. mkfifo library function

   Date :  20 Sep
*/


#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
int main() {
    mkfifo("myfifo19e", 0666);
    printf("FIFO Created\n");
    return 0;
}


/*
Output:
FIFO Created
*/