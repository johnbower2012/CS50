#include "binarytree.h"

/********* BINARY TREE *********/
void createTree(binarytree **root)
{
  int num;
  int c;
  while( printf("number: ") && scanf("%i",&num) )
    {
      binarytree *t = malloc(sizeof(binarytree));
      t->number = num;
      t->depth = 0;
      t->lefttree = NULL;
      t->righttree = NULL;
      if( !*root )
	{
	  *root = t;
	}
      else
	{
	  for(binarytree *ptr = *root; ptr != NULL; )
	    {
	      t->depth++;
	      if(t->number < ptr->number)
		{
		  if(!ptr->lefttree)
		    {
		      ptr->lefttree = t;
		      break;
		    }
		  else
		    {
		      ptr = ptr->lefttree;
		    }
		}
	      else
		{
		  if(!ptr->righttree)
		    {
		      ptr->righttree = t;
		      break;
		    }
		  else
		    {
		      ptr = ptr->righttree;
		    }
		}
	    }
	}
    }
  while( (c = getchar()) != '\n' && c != EOF );
}
void printTree(binarytree **parent)
{
  binarytree *ptr = *parent;
  if( ptr != NULL )
    {
      printf("depth%i: %i\n",ptr->depth,ptr->number);
      printf("l: ");
      printTree(&ptr->lefttree);
      printf("r: ");
      printTree(&ptr->righttree);
    }
  else
    {
      printf("HIT LEAF\n");
    }
}
void printTreeLtoG(binarytree **parent)
{
  binarytree *ptr = *parent;
  if( ptr != NULL )
    {
      printTreeLtoG(&ptr->lefttree);
      printf("%i\n",ptr->number);
      printTreeLtoG(&ptr->righttree);
    }
}
void deleteTree(binarytree **parent)
{
  binarytree *ptr = *parent;
  if( ptr != NULL )
    {
      deleteTree(&ptr->lefttree);
      deleteTree(&ptr->righttree);
      free(ptr);
    }
}
