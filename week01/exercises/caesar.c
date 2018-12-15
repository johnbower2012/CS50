#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char* argv[]){
  int cipher;
  if( argc != 2 ){
    printf("Usage: ./caesar k\n");
    exit(1);
  }else{
    cipher = atoi(argv[1]);
  }

  char buffer[500];
  printf("plaintext: ");
  fgets(buffer,sizeof(buffer),stdin);
  int i=0;
  printf("ciphertext: ");
  while( buffer[i] != '\0' ){
    if(isupper(buffer[i])){
      printf("%c",(buffer[i] + cipher - 'A')%26 + 'A');
    }else if(islower(buffer[i])){
      printf("%c",(buffer[i] + cipher - 'a')%26 + 'a');
    }else{
      printf("%c",buffer[i]);
    }
    i++;
  }

  return 0;
}
