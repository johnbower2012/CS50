#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary.h"


int main(void)
{
  dictionary *root = NULL;
  char **word;
  int words = 2;
  int *wordlengths;
  int keys=26;
  wordlengths = (int *)malloc(words*sizeof(int));
  word = (char **)malloc(words*sizeof(char *));
  wordlengths[0] = 6;
  wordlengths[1] = 6;

  for(int i=0;i<words;i++)
    {
      int wl = wordlengths[i];
      word[i] = (char *) malloc(wl*sizeof(char));
    }

  word[0][0] = 'A';
  word[0][1] = 'P';
  word[0][2] = 'P';
  word[0][3] = 'L';
  word[0][4] = 'E';
  word[0][5] = '\0';
  word[1][0] = 'A';
  word[1][1] = 'P';
  word[1][2] = 'E';
  word[1][3] = 'S';
  word[1][4] = '\0';
  word[1][5] = '\0';
  createDictionary(&root,word[0],keys);
  createDictionary(&root,word[1],keys);
  bool found;
  found = searchDictionary(&root,word[0]);
  if(found)
    {
      printf("found\n");
    }
  else
    {
      printf("not found\n");
    }
  found = searchDictionary(&root,word[1]);
  if(found)
    {
      printf("found\n");
    }
  else
    {
      printf("not found\n");
    }
  printDictionary(&root,keys);
  deleteDictionary(&root,keys);

  return 0;
}
