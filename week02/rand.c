#include "rand.h"

void randomize(int *array, int length, int scale, int mod)
{
  for(int i=0;i<length;i++){
    array[i] = (scale*rand())%mod;
  }
}
