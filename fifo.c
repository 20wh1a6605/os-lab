#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main(){
    int fd;
    char * fifo = "/tmp/newpipe";
    char arr[100],arr1[100];
    mkfifo(fifo,0666);
    while(1){
        fd = open(fifo, O_WRONLY);
        fgets(arr1,80,stdin);
        write(fd,arr1,strlen(arr1)+1);
        close(fd);
        fd = open(fifo,O_RDONLY);
        read(fd,arr,sizeof(arr));
        printf("user2 : %s\n",arr);
        close(fd);
        }
    return 0;
    }
