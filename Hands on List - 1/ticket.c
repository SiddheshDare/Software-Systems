#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
    int fd;
    struct{
        int n;
    } data;
    printf("Enter ticket no. : ");
    scanf("%d",&data.n);
    fd = open("ticket",O_CREAT|O_RDWR,0744);
    write(fd,&data,sizeof(data));
    close(fd);
    fd = open("ticket.txt",O_RDONLY);
    read(fd,&data,sizeof(data));
    printf("Ticket no. is : %d\n",data.n);
    close(fd);
}
/*
Output :
Enter ticket no. : 10
Ticket no. is : 10
*/