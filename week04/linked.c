#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(void)
{
  node *numbers = NULL;
  int c;
  buildList(&numbers);
  printList(&numbers);
  appendList(&numbers);
  printList(&numbers);
  deleteList(&numbers);

  return 0;
}
