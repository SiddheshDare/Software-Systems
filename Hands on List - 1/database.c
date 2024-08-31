#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
int main(){
    int fd;
    struct{
        int n,c;
    } data[3];
    for (int i = 0; i < 3; i++)
    {
        data[i].n = i+1;
        data[i].c = 0;
    }
    fd = open("database.txt",O_RDWR);
    write(fd,data,sizeof(data));
    close(fd);
}