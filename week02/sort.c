#include "sort.h"
#include "print.h"

void selectionSort(int *array, int length){
  int current,least,index;
  for(int i=0;i<length;i++){
    current = least = array[i];
    for(int j=i;j<length;j++){
      current = array[j];
      if(current <= least){
	least = current;
	index = j;
      }
    }
    current = array[i];
    array[i] = least;
    array[index] = current;
  }
}
void insertionSort(int *array, int length)
{
  int current,index;
  for(int i=1;i<length;i++)
    {
      current = array[i];
      index = i;
      while( current < array[index-1] && index > 0)
	{
	  array[index] = array[index-1];
	  index--;
	}
      array[index] = current;
    }
}
void bubbleSort(int *array, int length)
{
  int current;
  for(int i=0;i<length-1;i++)
    {
      for(int j=0;j<length-1-i;j++)
	{
	  if(array[j] > array[j+1])
	    {
	      current = array[j+1];
	      array[j+1] = array[j];
	      array[j] = current;
	    }
	}
    }
}

void mergeSort(int *array, int length){
  if(length>1)
    {
      //Split into right and left halves
      int lh = length/2,
	rh = length - lh;
      int *LH = (int *)malloc(lh * sizeof(int)),
	*RH = (int *)malloc(rh *sizeof(int));
  
      //Sort left half
      for(int i=0;i<lh;i++)
	LH[i] = array[i];
      mergeSort(LH,lh);

      //Sort left half
      for(int i=0;i<rh;i++)
	RH[i] = array[lh+i];
      mergeSort(RH,rh);
      
      //Merge the two halves
      int i=0,
	j=0;
      //while both halves are within range, continue to compare which is less
      //   in order to sort the original array
      while( (i < lh) && (j < rh) )
	{
	  if(LH[i] < RH[j])
	    {
	      array[i+j] = LH[i];
	      i++;
	    }
	  else
	    {
	      array[i+j] = RH[j];
	      j++;
	    }
	}
      //Once one half leaves its range, continue until the other also leaves range
      while( i < lh ) 
	{
	  array[i+j] = LH[i];
	  i++;
	}
      while( j < rh )
	{
	  array[i+j] = RH[j];
	  j++;
	}
      //Free memory
      free(LH);
      free(RH);
    }
}


void swap(int *a,int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int *array, int low, int high)
{
  int pivot = array[high];
  int i = low;
  for (int j = low; j < high; j++)
    {
      if(array[j] < pivot)
	{
	  if(i != j)
	    swap( &array[i], &array[j] );
	  i++;
	}
    }
  swap( &array[i], &array[high] );
  return i;
}  
void quickSort(int *array, int low, int high)
{
  if(low < high)
    {
      int p = partition(array, low, high);
      quickSort(array, low, p-1);
      quickSort(array, p+1, high);
    }
}

