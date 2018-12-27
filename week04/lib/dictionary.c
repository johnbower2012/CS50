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
void loadDictionary(dictionary **dict, char *filename, int keys)
{
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
  FILE* file = fopen(filename,"r");   
  char entry[256];
  if( file )
    {
      while( fgets(entry,sizeof(entry),file) )
	{
	  lc=0;
	  ptr = *dict;
	  while( entry[lc] != '\n' )
	    {
	      int let = 26;
	      if(isalpha(entry[lc]))
		{
		  let = (int) (toupper(entry[lc]) - 'A');
		}
	      if( !(ptr->letter[let]) )
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
	  ptr->word = (char *)malloc( (lc+1) * sizeof(char) );
	  for(int i=0;i<lc;i++)
	    {
	      ptr->word[i] = toupper(entry[i]);
	    }
	  ptr->word[lc] = '\0';
	}
    }
}
bool searchDictionary(dictionary **dict, char *entry)
{
  bool found=false;
  int lettercount=0;  

  dictionary *ptr = *dict;
  while( entry[lettercount] != '\0' )
    {
      int let = 26;
      if( isalpha(entry[lettercount]) )
	{
	  let = (int) (toupper(entry[lettercount]) - 'A');
	}
      if( ptr->letter[let] != NULL )
	{
	  ptr = ptr->letter[let];
	  lettercount++;
	  if(entry[lettercount] == '\0' && ptr->word)
	    {
	      int cmp = strcasecmp(ptr->word,entry);
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
      if( ptr->word != NULL)
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
int sizeDictionary(dictionary **cover, int keys)
{
  int count=0;
  dictionary *ptr = *cover;
  if( ptr != NULL )
    {
      if( ptr->word != NULL )
	{
	  count++;
	}
      for(int i=0;i<keys;i++)
	{
	  count += sizeDictionary(&ptr->letter[i],keys);
	}
    }
  return count;
}
