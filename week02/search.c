#include <stdio.h>


int linearSearch(int *array, int length, int sought){
  for(int i=0;i<length;i++)
    {
      if(array[i] == sought)
	{
	  return i;
	}
    }
  return -1;
}
int binarySearch(int *array, int length, int sought){
  int modlength = length/2,
    begin=0,
    end=length;
  while( length > 0)
    {
      printf("%d %d %d %d\n",begin,end,modlength,array[modlength]);
      if(array[modlength] == sought)
	{
	  return modlength;
	}
      else if(array[modlength] < sought)
	{
	  begin = modlength + 1;
	  modlength = (end + begin)/2;
	  length = (end - begin + 1)/2;
	}
      else
	{
	  end = modlength;
	  modlength = (end + begin)/2;
	  length = (end - begin + 1)/2;
	}
    }
  printf("%d %d %d %d\n",begin,end,modlength,array[modlength]);
  return -1;
}
