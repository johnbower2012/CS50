#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "dictionary.h"
#include "file.h"

int main(int argc, char* argv[])
{
  int keys=27;
  dictionary *root = NULL;
  if( argc != 3 )
    {
      printf("Usage: ./dict dictionary.txt tocheck.txt\n");
	return 1;
    }

  // Benchmarks
  double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;
  clock_t before,after;
  before = clock();
  loadDictionary(&root,argv[1],keys);
  after = clock();
  time_load = (after - before)/(double) CLOCKS_PER_SEC;

  FILE *file = fopen(argv[2],"r");
  int words=0;
  int misspellings=0;
  char word[LENGTH+1];
  int index=0;
  if( !file )
    {
      printf("Unable to open file.\n");
      return 1;
    }

  // Prepare to report misspellings
  printf("\nMISSPELLED WORDS\n\n");

  // Spell-check each word in text
  before = clock();
  for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {
      // Allow only alphabetical characters and apostrophes
      if (isalpha(c) || (c == '\'' && index > 0))
        {
	  // Append character to word
	  word[index] = c;
	  index++;

	  // Ignore alphabetical strings too long to be words
	  if (index > LENGTH)
            {
	      // Consume remainder of alphabetical string
	      while ((c = fgetc(file)) != EOF && isalpha(c));

	      // Prepare for new word
	      index = 0;
            }
        }

      // Ignore words with numbers (like MS Word can)
      else if (isdigit(c))
        {
	  // Consume remainder of alphanumeric string
	  while ((c = fgetc(file)) != EOF && isalnum(c));

	  // Prepare for new word
	  index = 0;
        }

      // We must have found a whole word
      else if (index > 0)
        {
	  // Terminate current word
	  word[index] = '\0';
	  words++;

	  // Check word's spelling
	  bool misspelled = !searchDictionary(&root,word);

	  // Print word if misspelled
	  if (misspelled)
            {
	      printf("%s\n", word);
	      misspellings++;
            }

	  // Prepare for next word
	  index = 0;
        }
    }
  after = clock();
  time_check = (after - before)/(double) CLOCKS_PER_SEC;

  // Determine dictionary's size
  before = clock();
  int n = sizeDictionary(&root,keys);
  after = clock();
  time_size = (after - before)/(double) CLOCKS_PER_SEC;

  //deleting dictionary
  before = clock();
  deleteDictionary(&root,keys);
  after = clock();
  time_unload = (after - before)/(double) CLOCKS_PER_SEC;

  printf("\nWORDS MISSPELLED:     %d\n", misspellings);
  printf("WORDS IN DICTIONARY:  %d\n", n);
  printf("WORDS IN TEXT:        %d\n", words);
  printf("TIME IN load:         %.2f\n", time_load);
  printf("TIME IN check:        %.2f\n", time_check);
  printf("TIME IN size:         %.2f\n", time_size);
  printf("TIME IN unload:       %.2f\n", time_unload);
  printf("TIME IN TOTAL:        %.2f\n\n",time_load+time_check+time_size+time_unload);


  return 0;
}
