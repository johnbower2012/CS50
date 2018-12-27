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
int cat_file(FILE *file)
{
  if( file )
    {
      char ch;
      while( (ch = fgetc(file)) != EOF )
	printf("%c",ch);//fputc(ch,outfile);
      fclose(file);
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
int load(char *name)
{
  FILE* file = fopen(name,"r");   
  char line[256];
  if( file )
    {
      while( fgets(line,sizeof(line),file) )
	{
	  int i=0;
	  while( line[i] != '\0' )
	    {
	      printf("%c",line[i]);
	      printf("%c",line[i]);
	      i++;
	    }
	}
      return 0;
    }
  else
    {
      return 1;
    }
}
