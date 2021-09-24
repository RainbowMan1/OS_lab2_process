#include <stdio.h>
#include <stdlib.h>


int main (){

  int num_childs = 2;
  int pid[num_childs];
  int i; 
  for (i = 0; i<num_childs; i++){
    pid[i] = fork();

    if (pid[i] == 0) child_process();
    else if (pid[i]<0) exit(1);
  }

  for (i=0; i < num_childs; i++){
    int status;
    int completed_pid = wait(&status);
    printf("Child Pid: %d has completed with exit status: %d\n", completed_pid, status);
  }
}

void child_process(){
  int my_pid = getpid();
  int parent_pid = getppid();
  srandom(my_pid % 42);
  int num_iterations = 1 + (random() % 30);
  int i;
  for (i=0; i < num_iterations; i++){
    int sleep_time = 1 + (random() % 10);
    printf("Child Pid: %d  is going to sleep for %d seconds!\n", my_pid, sleep_time);
    sleep(sleep_time);
    printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", my_pid, parent_pid);
  }
  exit(0);
}
