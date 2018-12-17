#include <stdio.h>
#include <stdlib.h>

int factorial(int m);

int main(int argc, char *argv[])
{
  if( argc != 2)
    {
    printf("Usage: ./factorial m\n");
    exit(1);
    }
  else
    {
      int m = atoi(argv[1]);
      printf("%d\n",factorial(m));
    }

  return 0;
}

int factorial(int m)
{
  if(m < 0)
      return 0;
  else if(m == 0 || m == 1)
    return 1;
  else
    return m * factorial(m-1);
}
    
