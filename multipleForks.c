// Author: jyotir07 @github
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  fork();
  fork();
  fork();
  //if we use 'space' in double quots in print statement, 
  printf("Hello World ");  //weird thing fork does it returns different outputs for some reason in multiple compilers 
  return 0;
}
