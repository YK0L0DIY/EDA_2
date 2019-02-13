#include <stdio.h>

int fib(int n)
{
  if (n == 0 || n == 1)
    return n;
  else
    return (fib(n-1) + fib(n-2));
}

int main(void){

  int i=0,c;

  for (c = 1; c <= 20; c++)
  {
    printf("%d\n", fib(i));
    i++;
  }
  return 0;
}
