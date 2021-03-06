#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
#include "search.h" 
#include "print.h"
#include "rand.h"


int main(int argc, char* argv[]){
  int length;
  if(argc != 2 )
    {
      printf("Usage: ./main length\n");
      exit(1);
    }
  else
    length=atoi(argv[1]);

  int scale=1;
  int mod=length;
  int *array = malloc(length*sizeof(int));
  clock_t start,end;


  randomize(array,length,scale,mod);
  //printInt(array,length);
  start = clock();
  quickSort(array,0,length-1);
  end = clock();
  printf("QuickSort: %fs\n", (double)(end-start)/(double)CLOCKS_PER_SEC);
  //printInt(array,length);

  randomize(array,length,scale,mod);
  //printInt(array,length);
  start = clock();
  mergeSort(array,length);
  end = clock();
  printf("MergeSort: %fs\n",(double)(end-start)/(double)CLOCKS_PER_SEC);
  //printInt(array,length);

  randomize(array,length,scale,mod);
  //printInt(array,length);
  start = clock();
  insertionSort(array,length);
  end = clock();
  printf("InsertionSort: %fs\n",(double)(end-start)/(double)CLOCKS_PER_SEC);
  //printInt(array,length);

  randomize(array,length,scale,mod);
  //printInt(array,length);
  start = clock();
  bubbleSort(array,length);
  end = clock();
  printf("BubbleSort: %fs\n",(double)(end-start)/(double)CLOCKS_PER_SEC);
  //printInt(array,length);

  randomize(array,length,scale,mod);
  //printInt(array,length);
  start = clock();
  selectionSort(array,length);
  end = clock();
  printf("SelectionSort: %fs\n",(double)(end-start)/(double)CLOCKS_PER_SEC);
  //printInt(array,length);

  free(array);

  return 0;

}
