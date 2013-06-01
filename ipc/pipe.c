#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdio.h>
int main(int argc, char** argv)
{
    int pipe1[2];
    pipe(pipe1);
    pid_t child1, child2;
    if((child2 = fork()) == 0) {
      //close(pipe1[1]);
      //char buf[1000];
      //read(pipe1[0], buf, 10);
      //printf("%s", buf);
      dup2(pipe1[0], STDIN_FILENO);
      //close(pipe1[0]);
      execl("/bin/ls", "ls", NULL);
      dup2(0, STDIN_FILENO);
      return 0;
    }
    if((child1 = fork()) == 0) {
      //close(pipe1[0]);
      dup2(pipe1[1], STDOUT_FILENO);
      //close(pipe1[1]);
      execl("/bin/ls", "ls", NULL);
      //write(pipe1[1], "hello world\n", 10);
      return 0;
    } 
    waitpid(child2, NULL, 0);
    waitpid(child1, NULL, 0);
    return 0;
}
