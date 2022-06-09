   #include<stdlib.h>
   #include<stdio.h>
   #include<unistd.h>
   #include<fcntl.h>
   #include<pthread.h>
   #include<sys/stat.h>
   #include<sys/types.h>
   int main(){
      int fd;
      char * myfifo = "/tmp/newpipe";
      char str1[80],str2[80];
      mkfifo(myfifo,0666);
      while(1){
          fd = open(myfifo, O_RDONLY);
          read(fd,str1,80);
          printf("user1 : %s",str1);
          close(fd);
          fd = open(myfifo, O_RDONLY);
          fgets(str2,80,stdin);
          write(fd,str2,80);
          close(fd);
          }
      return 0;
      }


