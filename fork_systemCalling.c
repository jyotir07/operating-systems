/*code by Jyotiraditya Singh.*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t p = fork();
  if (p < 0)
  {
    printf("Fork failed");
  }
  printf("Process ID of child process: %d", getpid());
  return 0;
}
