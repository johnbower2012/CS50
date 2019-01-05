#include "file.h"

int cat(char *name)
{
  FILE* infile = fopen(name,"r");  
  if( infile )
    {
      char ch;
      while( (ch = fgetc(infile)) != EOF )
	printf("%c",ch);//fputc(ch,outfile);
      fclose(infile);
      //fclose(outfile);
      return 0;
    }
  else
    return 1;
}
int cp(char *namein, char *nameout)
{
  FILE* infile = fopen(namein,"r");  
  FILE* outfile = fopen(nameout,"w");
  if( infile && outfile )
    {
      char ch;
      while( (ch = fgetc(infile)) != EOF )
	fputc(ch,outfile);
      fclose(infile);
      fclose(outfile);
      return 0;
    }
  else
    return 1;
}
