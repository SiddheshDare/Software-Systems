/* 
   Name : 11.c
   Author: Siddhesh Dare
   Description :11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
                    use sigaction system call.

   Date :  12 Sep
*/


#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    struct sigaction s;
    s.sa_handler = SIG_IGN;
    s.sa_flags = 0;
    printf("Ignoring SIGINT\n");
    sigaction(SIGINT,&s,NULL);
    sleep(10);
    printf("\nSIGINT set to default action\n");
    s.sa_handler = SIG_DFL;
    s.sa_flags = 0;
    sigaction(SIGINT,&s,NULL);
    sleep(5);
    return 0;
}


/*
Output:
sid@sid-Inspiron-3505:~/List2$ ./a.out
Ignoring SIGINT
^C^C^C^C^C
SIGINT set to default action
^C
sid@sid-Inspiron-3505:~/List2$
*/