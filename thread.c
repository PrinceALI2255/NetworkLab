#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

void fibonaci(void * );
void prime(void * );
int n, i, flag = 0;

int main() 
{
  printf("Enter an integer: ");
  scanf("%d", & n);
  pthread_t p1, p2;
  pthread_create( & p1, NULL, (void * ) fibonaci, NULL);
  pthread_create( & p2, NULL, (void * ) prime, NULL);
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  return 0;
}

void fibonaci(void * p1) 
{
  int a = 0, b = 1, c, d;
  if (n == 1) 
  {
    printf("\nFibonaci Series:\n%d\n", a);
  } 
  else if (n < 1) 
  {
    printf("\nInvalid Input\n");
  }
  else 
  {
    d = n - 2;
    printf("\nFibonaci Series:\n%d\n%d\n", a, b);
    while (d != 0) 
    {
      c = a + b;
      printf("%d\n", c);
      a = b;
      b = c;
      d--;
    }
  }
}
void prime(void * p2) 
{
  if (n == 1) 
  {
    printf("\n1 is neither prime nor composite\n");
  } 
  else if (n == 0) 
  {
    printf("\nInvalid Input\n");
  } 
  else 
  {
    for (i = 2; i <= (n / 2); i++) 
    {
      if (n % i == 0) 
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0) 
    {
      printf("\n%d ---> Is a Prime Number\n\n", n);
    } 
    else 
    {
      printf("\n%d ---> Not a Prime Number\n\n", n);
    }
  }
}
