#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "search.h" 
#include "print.h"

#define PI 3.1412

int main(int argc, char* argv[]){
  int length=25;
  int array[25] = {4,6,12,34,100,101,-102,88,92,30,37,18,1,1,1,1,1,4,30,4,1,7,8,-33,-44};
  
  
  printInt(array,length);

  mergeSort(array,length);

  printInt(array,length);

  return 0;

}
