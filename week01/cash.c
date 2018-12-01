#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void makeChange();

int main(void){
  makeChange();

  return 0;
}

void makeChange(){
  double number;
  char buffer[500],*endptr;
  int loop=1,change;
  do
    {
      printf("Change owed: ");
      fgets(buffer,sizeof(buffer),stdin);
      number = strtod(buffer, &endptr);
      if(buffer == endptr) continue;
      while(isspace((unsigned char) *endptr)) endptr++;
      if( *endptr != '\0' ) continue;
      if(number<0) continue;
      loop=0;
    } 
  while(loop);
  change = (int)( number*1000);
  if(change%10 != 0) change+=10;
  change /= 10;
  int count=0;
  while(change>24){
    change -= 25;
    count++;
  }
  while(change>9){
    change -= 10;
    count++;
  }
  while(change>4){
    change -= 5;
    count++;
  }
  while(change>0){
    change -= 1;
    count++;
  }
  printf("%d\n",count);
}
