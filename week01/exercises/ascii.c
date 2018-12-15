#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
  char s[100];
  fgets(s,sizeof(s),stdin);
  printf("%i\n",(int) strlen(s));
  for(int i=0, n = strlen(s); i < n; i++){
    printf("%c", toupper(s[i]));
  }

  return 0;
}
