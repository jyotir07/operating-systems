#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  fork();
  fork();
  fork();
  printf("Hello World ");
  return 0;
}