#define _XOPEN_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char* argv[]){
  char *hashed, 
    salt[2],
    pass[6],
    characters[52],
    frequency[52] = "etaoinsrhldcumfpgwybvkxjqzETAOINSRHLDCUMFPGWYBVKXJQZ";
  int breakout=0,
    letterfrequency=1;
  clock_t start,end;
  double time;

  if( argc != 2 ){
    printf("Usage: ./crack hash\n");
    exit(1);
  }else{
    hashed = argv[1];
    salt[0] = hashed[0];
    salt[1] = hashed[1];
  }

  for(int i = 0; i < strlen(pass);i++){
    pass[i] = '\0';
  }
  if(letterfrequency==0){
    for(int i=0;i<52;i++){
      if(i<26){
	characters[i] = (char) (i + 'a');
      }else{
	characters[i] = (char) (i + 'A' - 26);      
      }
    }
  }else{
    for(int i=0;i<52;i++){
      characters[i] = frequency[i];
    }
  }



  start = clock();
  for( int p = 0; p< 52;p++){
    for( int i = 0; i < 52; i++){
      for( int j = 0; j < 52; j++){
	for( int k = 0; k < 52; k++){
	  for( int l = 0; l < 52; l++){
	    if(breakout==1) break;
	    pass[0] = characters[l];
	    if(strcmp(crypt(pass,salt),hashed) == 0){
	      printf("pass:%s\n",pass);
	      breakout=1;
	    break;
	  }
	  }
	  if(breakout==1) break;
	  pass[1] = characters[k];
	  if(strcmp(crypt(pass,salt),hashed) == 0){
	    printf("pass:%s\n",pass);
	    breakout=1;
	    break;
	  }
	}
	if(breakout==1) break;
	pass[2] = characters[j];
	if(strcmp(crypt(pass,salt),hashed) == 0){
	  printf("pass:%s\n",pass);
	  breakout=1;
	  break;
	}
      }
      if(breakout==1) break;
      pass[3] = characters[i];
      if(strcmp(crypt(pass,salt),hashed) == 0){
	printf("pass:%s\n",pass);
	breakout=1;
	break;
      }
    }
    if(breakout==1) break;
    pass[4] = characters[p];    
    if(strcmp(crypt(pass,salt),hashed) == 0){
      printf("pass:%s\n",pass);
      breakout=1;
      break;
    }
  }
  end = clock();
  printf("time: %fs\n",(double)(end-start)/(double)CLOCKS_PER_SEC);

  return 0;
}
