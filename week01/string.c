#include<stdio.h>

#include<string.h>
#include<ctype.h>

int main(void){
  char buffer[500], *endptr;
  printf("Enter some text! ");
  fgets(buffer,sizeof(buffer),stdin);

  int i=0;

  for(int j=0;j<strlen(buffer);j++){
    if(isupper(buffer[j])){
      printf("%c",tolower(buffer[j]));
    }else{
      printf("%c",buffer[j]);
    }
  }    

  while(buffer[i]!='\0'){
    if(islower(buffer[i])){
      printf("%c",toupper(buffer[i]));
    }else{
      printf("%c",buffer[i]);
    }
    i++;
  }
  return 0;
}
