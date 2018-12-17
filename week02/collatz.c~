#include <stdio.h>
#include <stdlib.h>

int collatz(int m);

int main(int argc, char* argv[]){
  if(argc != 2)
    {
      printf("Usage: ./collatz m\n");
      exit(1);
    }
  else
    {
      int m = atoi(argv[1]);
      printf("%d\n",collatz(m));
    }

  return 0;
}

int collatz(int m)
{
  if(m<1)
    return -1;
  else if(m==1)
    return 0;
  else if(m%2==0)
    return collatz(m/2) + 1;
  else
    return collatz(3*m+1) + 1;
}
