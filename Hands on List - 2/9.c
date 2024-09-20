/* 
   Name : 9.c
   Author: Siddhesh Dare
   Description :9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
                   signal - Use signal system call.
   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
int main(){
    signal(SIGINT,SIG_IGN);
    printf("Ignoring SIGINT\n");
    sleep(10);
    printf("\nSIGINT set to default action\n");
    signal(SIGINT,SIG_DFL);
    sleep(10);
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./a.out
Ignoring SIGINT
^C^C^C^C^C^C
SIGINT set to default action
^C
sid@sid-Inspiron-3505:~/List2$
*/