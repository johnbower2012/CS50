#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dictionary.h"


int main(void)
{
  dictionary *root;
  char **word;
  int words = 1;
  int *wordlengths;
  int keys=26;
  wordlengths = (int *)malloc(words*sizeof(int));
  word = (char **)malloc(words*sizeof(char *));
  for(int i=0;i<words;i++)
    {
      word[i] = (char *) malloc(6*sizeof(char));
    }

  wordlengths[0] = 6;
  word[0][0] = 'A';
  word[0][1] = 'P';
  word[0][2] = 'P';
  word[0][3] = 'L';
  word[0][4] = 'E';
  word[0][5] = '\0';

  createDictionary(&root,word[0],keys);
  printf("%s\n",word[0]);
  bool found = searchDictionary(&root,word[0]);
  printDictionary(&root,keys);
  deleteDictionary(&root,keys);

  return 0;
}
