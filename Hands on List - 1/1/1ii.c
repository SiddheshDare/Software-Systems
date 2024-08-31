/* 
   Name : 1(ii).c
   Author: Siddhesh Dare
   Description :1. Create the following types of a files using (ii)system call
                a. soft link (symlink system call)
                b. hard link (link system call)
                c. FIFO (mkfifo Library Function or mknod system call)
    Date :  30 Aug          
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
    int s = symlink("file.txt","Sftlnk");
    if(s<0) perror("Failed");
    else printf("Softlink created.\n");
    int h = link("file.txt","Hardlnk");
    if(h<0) perror("Failed");
    else printf("Hardlink created.\n");
    int m = mknod("MyFIFO",S_IFIFO,0);
    if(m<0) perror("Failed");
    else printf("FIFO created.\n");
    return 0;
}


/*
Output : Softlink created.
         Hardlink created.
         FIFO created.
         -rw-rw-r-- 2 sid sid     0 Aug 30 18:04 file.txt
         -rw-rw-r-- 2 sid sid     0 Aug 30 18:04 Hardlnk
         p--------- 1 sid sid     0 Aug 30 18:16 MyFIFO|
         lrwxrwxrwx 1 sid sid     8 Aug 30 18:16 Sftlnk -> file.txt
*/