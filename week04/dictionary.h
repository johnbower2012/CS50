#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <ctype.h>

/********* DICTIONARY *********/
typedef struct dictionary
{
  char *word;
  struct dictionary **letter;
}
dictionary;

void createDictionary(dictionary **dict, char *word, int keys);
bool searchDictionary(dictionary **dict, char *word);
void printDictionary(dictionary **cover, int keys);
void deleteDictionary(dictionary **cover, int keys);

#endif

