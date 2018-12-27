#include "dictionary.h"

/********* DICTIONARY *********/
void createDictionary(dictionary **dict, char *entry, int keys)
{
  int len = strlen(entry)+1;
  int let, lc=0;
  dictionary *ptr = *dict;

  if( !ptr )
    {
      ptr = (dictionary*)malloc(sizeof(dictionary));
      ptr->word = NULL;
      ptr->letter = (dictionary**)malloc(keys*sizeof(dictionary*));
      for(int i=0;i<keys;i++)
	{
	  ptr->letter[i] = NULL;
	}
      *dict = ptr;
    }
  while( entry[lc] != '\0' )
    {
      int let = ((int) (toupper(entry[lc]) - 'A') + 26)%26;
      if( !ptr->letter[let] )
	{
	  ptr->letter[let] = (dictionary*)malloc(sizeof(dictionary));
	  ptr = ptr->letter[let];
	  ptr->word = NULL;
	  ptr->letter = (dictionary**)malloc(keys*sizeof(dictionary*));
	  for(int i=0;i<keys;i++)
	    {
	      ptr->letter[i] = NULL;
	    }
	}
      else
	{
	  ptr = ptr->letter[let];	      
	}
      lc++;
    }
  ptr->word = (char *)malloc(len*sizeof(char));
  for(int i=0;i<len;i++)
    {
      ptr->word[i] = entry[i];
    }
}
bool searchDictionary(dictionary **dict, char *entry)
{
  char c;
  bool found=false;
  int lettercount=0;
  for(dictionary *ptr = *dict; ptr != NULL; )
    {
      int let = (int) (entry[lettercount] - 'A');
      if( ptr->letter[let] != NULL )
	{
	  ptr = ptr->letter[let];
	  lettercount++;
	  if(entry[lettercount] == '\0')
	    {
	      int cmp = strcmp(ptr->word,entry);
	      if(cmp==0)
		{
		  found=true;
		}
	      break;
	    }
	}
      else
	{
	  break;
	}
    }
  return found;
}
void printDictionary(dictionary **cover, int keys)
{
  dictionary *ptr = *cover;
  if( ptr != NULL )
    {
      if( ptr->word != NULL )
	{
	  printf("%s\n",ptr->word);
	}
      for(int i=0;i<keys;i++)
	{
	  printDictionary(&ptr->letter[i],keys);
	}
    }
}
void deleteDictionary(dictionary **cover, int keys)
{
  dictionary *ptr = *cover;
  if( ptr != NULL )
    {
      if(!ptr->word)
	{
	  free(ptr->word);
	}
      for(int i=0; i<keys;i++)
	{
	  deleteDictionary(&ptr->letter[i],keys);
	}
      free(ptr);
    }
}
