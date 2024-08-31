/* 
   Name : 5.c
   Author: Siddhesh Dare
   Description :5. Write a program to create five new files with infinite loop. Execute the program in the background
                   and check the file descriptor table at /proc/pid/fd.
   Date :  30 Aug
*/


#include<fcntl.h>
int main(){
    while(1){
        creat("file_1",O_CREAT);
        creat("file_2",O_CREAT);
        creat("file_3",O_CREAT);
        creat("file_4",O_CREAT);
        creat("file_5",O_CREAT);
    }
}


/*
Output: use ls -l /proc/pid/fd on shell
total 0
lrwx------ 1 sid sid 64 Aug 30 18:44 0 -> /dev/pts/1
lrwx------ 1 sid sid 64 Aug 30 18:44 1 -> /dev/pts/1
lrwx------ 1 sid sid 64 Aug 30 18:44 2 -> /dev/pts/1
l-wx------ 1 sid sid 64 Aug 30 18:44 3 -> /home/sid/List1/file_1
l-wx------ 1 sid sid 64 Aug 30 18:44 4 -> /home/sid/List1/file_2
l-wx------ 1 sid sid 64 Aug 30 18:44 5 -> /home/sid/List1/file_3
l-wx------ 1 sid sid 64 Aug 30 18:44 6 -> /home/sid/List1/file_4
l-wx------ 1 sid sid 64 Aug 30 18:44 7 -> /home/sid/List1/file_5
*/