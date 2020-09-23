#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
  pid_t  pid;
  
  pid_t first_child_pid = fork();
  pid_t second_child_pid = -1;
  
  if(first_child_pid > 0){
    second_child_pid = fork();
    if(second_child_pid > 0){
      ParentProcess();
    }else{
      srand(842091);
      // Process for child two
      ChildProcess();
    }
  }else{
    srand(298487123);
    // Process for child one
    ChildProcess();
  }
  
  return 0;
}

int random_int_getter(int minimum, int maximum)
{
   return minimum + rand() % (maximum+1 - minimum);
}

void  ChildProcess(void)
{ 
  int i;
  pid_t ppid = getppid();
  pid_t pid = getpid();
  
  for (i = 1; i <= 30; i++){
    printf("Child Pid: %d is going to sleep!\n", pid);
    sleep(random_int_getter(1, 10));
    printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", pid, ppid);
  }
  exit(0);
}

void  ParentProcess(void)
{
  int status;
  pid_t copid = waitpid(-1, &status, 0);
  printf("Child Pid: %d has completed!\n", copid);
  
  pid_t ctpid = waitpid(-1, &status, 0);
  printf("Child Pid: %d has completed!\n", ctpid);
}
