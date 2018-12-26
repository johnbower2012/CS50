#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(void)
{
  binarytree *root = NULL;
  createTree(&root);
  printTreeLtoG(&root);
  createTree(&root);
  printTreeLtoG(&root);
  deleteTree(&root);
}
