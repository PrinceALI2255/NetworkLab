//fork2 pgm by Manish S
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{  
	int f1,f2,f3;
	f1=fork();
	if(f1>0)
	{
 		printf("Parent process P is created: %d\n", getpid());
		f2=fork();	
		if(f2==0)
 		{ 
   		printf("Child process C1 is created: %d\t PARENT = %d\n",getpid(),getppid());
	 		f3=fork();
	 		{
		 		if(f3==0)
		 		{
			 		printf("Child process C3 is created: %d\t PARENT = %d\n",getpid(),getppid());
		 		}
 			}
		}
	}
 
else if(f1==0)
	{
 		printf("\nChild process C2 created: %d\t PARENT = %d\n", getpid(),getppid());
	}
}
