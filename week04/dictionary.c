#include "dictionary.h"

/********* DICTIONARY *********/
void createDictionary(dictionary **dict, char *entry, int keys)
{
  int lettercount;
  lettercount=0;
  //If dictionary points to nothing, create root
  if( !(*dict) )
    {
      dictionary *new = malloc(sizeof(dictionary));
      new->word = NULL;
      new->letter = malloc(keys*sizeof(dictionary));
      for(int i=0;i<keys;i++)
	{
	  new->letter[i] = NULL;
	}
      *dict = new;
    }

  //loop through, creating new entries for new pathways
  for( dictionary* ptr = *dict; ptr != NULL; )
    {
  printf("pass\n");
      int let = (int) (entry[lettercount] - 'A');
      if( ptr->letter[let] != NULL )
	{
	  ptr = ptr->letter[let];
	}
      else
	{
	  dictionary *new = malloc(sizeof(dictionary));
	  new->word = NULL;
	  new->letter = (dictionary **)malloc(keys*sizeof(dictionary*));
	  for(int i=0;i<keys;i++)
	    {
	      new->letter[i] = NULL;
	    }
	  
	  ptr->letter[let] = new;
	  ptr = new;
	}
  printf("pass\n");
      lettercount++;
      if(entry[lettercount] == '\0')
	{
	  int size = lettercount+1;
	  ptr->word = malloc(size*sizeof(char));
	  for(int i=0;i<size;i++)
	    {
	      ptr->word[i] = entry[i];
	    }
	  printf("%s\n",ptr->word);
	  break;
	}
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
      for(int i=0;i<keys;i++)
	{
	  printDictionary(&ptr->letter[i],keys);
	}
      if( ptr->word != NULL )
	{
	  printf("%s\n",ptr->word);
	}
    }
}
void deleteDictionary(dictionary **cover, int keys)
{
  dictionary *ptr = *cover;
  if( ptr != NULL )
    {
      for(int i=0; i<keys;i++)
	{
	  deleteDictionary(&ptr->letter[i],keys);
	}
      free(ptr);
    }
}
