#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int main(void)
{
  dictionary *dict;
  int words=4;
  char word[4][10];

  word[0][0] = 'A';
  word[0][1] = 'P';
  word[0][2] = 'P';
  word[0][3] = 'L';
  word[0][4] = 'E';
  word[0][5] = '\0';

  word[1][0] = 'H';
  word[1][1] = 'A';
  word[1][2] = 'P';
  word[1][3] = 'P';
  word[1][4] = 'I';
  word[1][5] = 'N';
  word[1][6] = 'E';
  word[1][7] = 'S';
  word[1][8] = 'S';
  word[1][9] = '\0';

  word[2][0] = 'A';
  word[2][1] = 'C';
  word[2][2] = 'E';
  word[2][3] = '\0';

  word[3][0] = 'A';
  word[3][1] = 'C';
  word[3][2] = 'T';
  word[3][3] = '\0';

  int lettercount;
  for(int wordZ=0;wordZ<words;wordZ++)
    {
      lettercount=0;
      if( !dict )
	{
	  dictionary *new = malloc(sizeof(dictionary));
	  new->endword = 0;
	  for(int i=0;i<26;i++)
	    {
	      new->letter[i] = NULL;
	    }
	  dict = new;
	}
      for( dictionary* ptr = dict; ptr != NULL; )
	{
	  int let = (int) (word[wordZ][lettercount] - 'A');
	  if( ptr->letter[let] != NULL )
	    {
	      ptr = ptr->letter[let];
	    }
	  else
	    {
	      dictionary *new = malloc(sizeof(dictionary));
	      new->endword = 0;
	      for(int i=0;i<26;i++)
		{
		  new->letter[i] = NULL;
		}
	      ptr->letter[let] = new;
	      ptr = new;
	    }
	  lettercount++;
	  if(word[wordZ][lettercount] == '\0')
	    {
	      ptr->endword = 1;
	      printf("%s\n",word[wordZ]);
	      break;
	    }
	}
    }

  for(int wordZ=0;wordZ<words;wordZ++)
    {
      char c;
      int found=0;
      lettercount=0;
      if(dict != NULL)
	{
	  for(dictionary *ptr = dict; ptr != NULL; )
	    {
	      int let = (int) (word[wordZ][lettercount] - 'A');
	      if( ptr->letter[let] != NULL )
		{
		  ptr = ptr->letter[let];
		  lettercount++;
		  if(word[wordZ][lettercount] == '\0')
		    {
		      found = ptr->endword;
		      break;
		    }
		}
	      else
		{
		  break;
		}
	    }
	}
      printf("found%i: %s\n",found,word[wordZ]);
    }

  printDictionary(&dict);
  deleteDictionary(&dict);
}
