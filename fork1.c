//fork1 pgm by Manish S//
#include <stdio.h>
#include <unistd.h>
int main () 
{
  int f1,f2,f3,f4;
  f1=fork();
  if(f1 == 0) 
	{
    printf("Child process C1 created %d\t Parent = %d\n", getpid(),getppid());
    f2=fork();
    if(f2 == 0) 
		{
      printf("Child process C3 created %d\t Parent = %d\n", getpid(),getppid());
    } 
		else if(f2>0)
		{
      f3 = fork();
      if(f3 == 0) 
			{
        printf("Child process C4 is created %d\t Parent = %d\n", getpid(),getppid());
      }
    }
  } 
	else if(f1>0)
	{
    printf("Parent process P created %d\n", getpid());
    f4 = fork();
    if(f4 == 0) 
		{
      printf("Child process C2 is created %d\t Parent = %d\n", getpid(),getppid());
    }
  }
  return 0;
}
