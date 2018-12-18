#include <stdio.h>
#include <string.h>

void get_string(char* s);

int main(int argc, char* argv[])
{
  int charCount = 0;
  for(int i=1, n = argc - 1; i < argc; i++)
    {
      charCount += strlen(argv[i]);
      if(i != n) charCount++;
    }
  printf("%i characters entered to command line.\n",charCount);

  return 0;
}
