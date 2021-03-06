#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(int argc, char* argv[]){
  char* cipher;
  if( argc != 2 ){
    printf("Usage: ./caesar k\n");
    exit(1);
  }else{
    cipher = argv[1];
    int param=0;
    while(cipher[param] != '\0'){
      if(!(isalpha(cipher[param]))){
	exit(1);
      }
      param++;
    }
  }


  int ciph,j=0;
  char buffer[500];
  printf("plaintext: ");
  fgets(buffer,sizeof(buffer),stdin);

  printf("ciphertext: ");
  for(int i=0;i<strlen(buffer);i++){
    if(isalpha(cipher[i%(strlen(cipher))])){
      ciph = toupper(cipher[j%(strlen(cipher))]) - 'A';
    }

    if(isupper(buffer[i])){
      printf("%c",(buffer[i] + ciph - 'A')%26 + 'A');
      j++;
    }else if(islower(buffer[i])){
      printf("%c",(buffer[i] + ciph - 'a')%26 + 'a');
      j++;
    }else{
      printf("%c",buffer[i]);
    }

  }

  return 0;
}
