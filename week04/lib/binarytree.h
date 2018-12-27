#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stdio.h>
#include <stdlib.h>

/********* BINARY TREE *********/
typedef struct binarytree
{
  int number;
  int depth;
  struct binarytree *lefttree;
  struct binarytree *righttree;
} 
binarytree;

void createTree(binarytree **root);
void printTree(binarytree **root);
void printTreeLtoG(binarytree **parent);
void deleteTree(binarytree **parent);

#endif
