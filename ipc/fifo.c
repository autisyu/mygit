#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
#define FIFO1 "/tmp/fifo.1"
int main(int argc, char** argv)
{
    int pipe1[2];

    pipe(pipe1);
    pid_t child1, child2;
    mkfifo(FIFO1, 0777);
    if((child1 = fork()) == 0) {
      //close(pipe1[0]);
      int writefd = open(FIFO1, O_WRONLY, 0);
      write(writefd, "hello world\n", 10);
      return 0;
    } 
    if((child2 = fork()) == 0) {
      //close(pipe1[1]);
      char buf[1000];
      //read(pipe1[0], buf, 10);
      //printf("%s", buf);
      //close(pipe1[0]);
      int readfd = open(FIFO1, O_RDONLY, 0);
      read(readfd, buf, 10);
      printf("%s\n", buf);
      return 0;
    }
    waitpid(child2, NULL, 0);
    waitpid(child1, NULL, 0);
    return 0;
}
