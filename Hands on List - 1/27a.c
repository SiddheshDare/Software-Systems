/*
   Name : 27a.c
   Author: Siddhesh Dare
   Description :27. Write a program to execute ls -Rl by the following system calls
                    a. execl
   Date :  31 Aug
*/


#include<stdio.h>
#include<unistd.h>
int main(){
execl("/bin/ls","ls","-Rl",NULL);
}


/*
Output :
sid@sid-Inspiron-3505:~/List1$ ./a.out
.:
total 264
drwxrwxr-x 2 sid sid  4096 Aug 30 18:46 1
-rw-rw-r-- 1 sid sid  1178 Aug 31 14:49 10.c
-rw-rw-r-- 1 sid sid  1070 Aug 31 14:10 11.c
-rw-rw-r-- 1 sid sid   976 Aug 31 14:16 12.c
-rw-rw-r-- 1 sid sid  1015 Aug 31 14:16 13.c
-rw-rw-r-- 1 sid sid  1365 Aug 31 14:18 14.c
-rw-rw-r-- 1 sid sid  5335 Aug 31 14:19 15.c
-rw-rw-r-- 1 sid sid   897 Aug 31 14:19 16a.c
-rw-rw-r-- 1 sid sid   897 Aug 31 14:19 16b.c
-rw-rw-r-- 1 sid sid  1479 Aug 31 14:20 17.c
-rw-rw-r-- 1 sid sid  1439 Aug 31 14:20 18.c
-rw-rw-r-- 1 sid sid   586 Aug 31 14:21 19.c
-rw-rw-r-- 1 sid sid   479 Aug 31 14:22 20.c
-rw-rw-r-- 1 sid sid   570 Aug 31 14:23 21.c
-rw-rw-r-- 1 sid sid  1034 Aug 31 14:24 22.c
-rw-rw-r-- 1 sid sid   755 Aug 31 15:14 23.c
-rwxrwxr-x 1 sid sid 17648 Aug 29 15:39 24
-rw-rw-r-- 1 sid sid   706 Aug 31 14:29 24.c
-rw-rw-r-- 1 sid sid   946 Aug 31 16:22 25.c
-rw-rw-r-- 1 sid sid   738 Aug 31 14:29 26a.c
-rw-rw-r-- 1 sid sid   628 Aug 31 14:29 26b.c
-rw-rw-r-- 1 sid sid   401 Aug 31 16:44 27a.c
-rw-rw-r-- 1 sid sid   413 Aug 31 16:43 27b.c
-rw-rw-r-- 1 sid sid   472 Aug 31 16:26 28.c
-rw-rw-r-- 1 sid sid  1224 Aug 31 16:30 29.c
-rw-rw-r-- 1 sid sid  1926 Aug 31 14:00 2.c
-rw-rw-r-- 1 sid sid  1568 Aug 31 16:00 30.c
-rw-rw-r-- 1 sid sid   394 Aug 31 13:58 3.c
-rw-rw-r-- 1 sid sid   402 Aug 31 13:58 4.c
-rw-rw-r-- 1 sid sid  1012 Aug 31 14:08 5.c
-rw-rw-r-- 1 sid sid   357 Aug 31 13:59 6.c
-rw-rw-r-- 1 sid sid   795 Aug 31 14:06 7.c
-rw-rw-r-- 1 sid sid    51 Aug 30 19:09 7file1.txt
-rw------- 1 sid sid    51 Aug 30 19:11 7file2
-rw-rw-r-- 1 sid sid   581 Aug 31 14:07 8.c
-rw-rw-r-- 1 sid sid  1400 Aug 31 14:07 9.c
-rwxrwxr-x 1 sid sid 16056 Aug 31 13:16 Add
-rw-rw-r-- 1 sid sid   197 Aug 31 13:16 Add.c
-rwxrwxr-x 1 sid sid 15952 Aug 31 16:44 a.out
-rw-rw-r-- 1 sid sid     0 Aug 29 18:55 data
-rw-rw-r-- 1 sid sid   364 Aug 31 11:39 database.c
-rw-rw-r-- 1 sid sid    16 Aug 31 14:20 database.txt
-rw-rw-r-- 1 sid sid   122 Aug 29 15:43 exp23.c
-rw-rw-r-- 1 sid sid  1761 Aug 30 14:38 exp30.c
-rw-rw-r-- 1 sid sid   158 Aug  8 08:50 fifo.c
---x------ 1 sid sid     0 Aug 30 18:43 file_1
-rw-r-x--T 1 sid sid    30 Aug 31 14:48 file10.txt
-rwxrwxr-x 1 sid sid    83 Aug 30 22:16 file11.txt
---x------ 1 sid sid     0 Aug 30 18:43 file_2
---x------ 1 sid sid     0 Aug 30 18:43 file_3
---x------ 1 sid sid     0 Aug 30 18:43 file_4
---x------ 1 sid sid     0 Aug 30 18:43 file_5
-rwxrwxr-x 1 sid sid 15952 Aug 31 13:07 Hello
-rw-rw-r-- 1 sid sid   137 Aug 31 13:07 Hello.c
-rwxr--r-- 1 sid sid     0 Aug 30 18:28 newfile
-rw-rw-r-- 1 sid sid    79 Aug 21 22:53 read.txt
-rwxr--r-- 1 sid sid     4 Aug 31 11:15 ticket
-rw-rw-r-- 1 sid sid   520 Aug 31 11:16 ticket.c
-rwx------ 1 sid sid    71 Aug 31 14:24 write.txt

./1:
total 20
-rw-rw-r-- 1 sid sid  1107 Aug 31 13:56 1ii.c
-rwxrwxr-x 1 sid sid 16104 Aug 30 18:16 a.out
-rw-rw-r-- 2 sid sid     0 Aug 30 18:04 file.txt
-rw-rw-r-- 2 sid sid     0 Aug 30 18:04 Hardlnk
p--------- 1 sid sid     0 Aug 30 18:16 MyFIFO
lrwxrwxrwx 1 sid sid     8 Aug 30 18:16 Sftlnk -> file.txt
*/