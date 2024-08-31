/* 
   Name : 9.c
   Author: Siddhesh Dare
   Description :9. Write a program to print the following information about a given file.
                   a. inode
                   b. number of hard links
                   c. uid
                   d. gid
                   e. size
                   f. block size
                   g. number of blocks
                   h. time of last access
                   i. time of last modification
                   j. time of last change
   Date :  30 Aug
*/


#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
struct stat sfile;
int main(){
    stat("2.c",&sfile);
    printf("inode : %ld\n",sfile.st_ino);
    printf("number of hard links : %ld\n",sfile.st_nlink);
    printf("uid : %d\n",sfile.st_uid);
    printf("gid : %d\n",sfile.st_gid);
    printf("size : %ld\n",sfile.st_size);
    printf("block size : %ld\n",sfile.st_blksize);
    printf("number of blocks : %ld\n",sfile.st_blocks);
    printf("time of last access : %ld\n",sfile.st_atime);
    printf("time of last modification : %ld\n",sfile.st_mtime);
    printf("time of last change : %ld\n",sfile.st_ctime);
    return 0;
}


/*
Output :
inode : 283742
number of hard links : 1
uid : 1000
gid : 1000
size : 1886
block size : 4096
number of blocks : 8
time of last access : 1725022859
time of last modification : 1725022859
time of last change : 1725022859
*/
