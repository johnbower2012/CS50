#include <stdio.h>
#include <stdlib.h>

void cut_value(int length, int **cut, int **value);
int segment_value(int length);
void print_array(int n, int *array);
void print_arrangement(int n, int *cuts, int *val);

int main(int argc, char* argv[])
{
  if(argc!=2)
    {
      printf("Usage: ./cut length\n");
      return 1;
    }

  int n = atoi(argv[1]);
  int *cuts, *vals;

  cut_value(n,&cuts,&vals);
  print_arrangement(n,cuts,vals);

  free(cuts);
  free(vals);

  return 0;
}


void cut_value(int length, int **cuts, int **values)
{
  int max_val,max_cut,temp;
  int *cut = (int *)malloc((length+1)*sizeof(int));
  int *value = (int *)malloc((length+1)*sizeof(int));
  value[0] = 0;
  cut[0]=0;
  for(int i=1; i<length+1; i++)
    {
      max_val=segment_value(i);
      max_cut=i;
      for(int j=1; j<i+1; j++)
	{
	  temp = segment_value(j) + value[i-j];
	  if( temp > max_val )
	    {
	      max_val = temp;
	      max_cut = j;
	    }
	}
      value[i] = max_val;
      cut[i] = max_cut;
    }
  *cuts = cut;
  *values = value;
}
int segment_value(int length)
{
  int value=0;
  if(length == 1 )
    {
      value=1;
    }
  else if(length == 2)
    {
      value=5;
    }
  else
    {
      value=length+5;
    }
  return value;
}
void print_array(int n, int *array)
{
  for(int i=0;i<n;i++)
    {
      printf("%i ",array[i]);
    }
  printf("\n");
}
void print_arrangement(int n, int *cuts, int *val)
{
  int j=0,cut;
  for(int i=1;i<n+1;i++)
    {
      cut = cuts[i];
      printf("%i-%i: %i ",i,val[i],cut);
      j=i-cut;
      while( j > 0 )
	{
	  cut = cuts[j];
	  printf("%i ",cut);
	  j-=cut;
	}
      printf("\n");
    }
}
