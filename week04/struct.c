#include "struct.h"

/********* LINKED LIST *********/
void buildList(node **numbers){
  int num;
  printf("Enter integers to append to the list:\n");
  while( printf("number: ") && scanf("%i",&num) )
    {
       //Search for number in chain
      bool found=false;
      for(node *ptr=*numbers; ptr != NULL; ptr = ptr->next)
	{
	  if(ptr->number==num)
	    {
	      found=true;
	      break;
	    }	  
	}

      //add number to list if not found
      if(!found)
	{
	  node *n=malloc(sizeof(node));
	  if(!n)
	    {
	      break;
	    }
	  else{
	    n->number = num;
	    n->next = NULL;
	    if(*numbers)
	      {
		for(node *ptr = *numbers; ptr != NULL; ptr = ptr->next)
		  {
		    if(!ptr->next)
		      {
			ptr->next = n;
			break;
		      }
		  }
	      }
	    else
	      {
		*numbers = n;
	      }
	  }
	}
    }
  int c;
  while( (c = getchar()) != '\n' && c != EOF ){}
}
void appendList(node **numbers){
  int num;
  printf("Enter integers to insert into the list:\n");
  while( printf("number: ") && scanf("%i",&num) )
    {
       //Search for number in chain
      bool found=false;
      for(node *ptr=*numbers; ptr != NULL; ptr = ptr->next)
	{
	  if(ptr->number==num)
	    {
	      found=true;
	      break;
	    }	  
	}

      //add number to list if not found
      if(!found)
	{
	  node *n=malloc(sizeof(node));
	  if(!n)
	    {
	      break;
	    }
	  else if(*numbers)
	    {
	      n->number = num;
	      n->next = *numbers;
	      *numbers = n;
	    }
	  else
	    {
	      n->number = num;
	      n->next = NULL;
	      *numbers = n;
	    }
	}
    }
  int c;
  while( (c = getchar()) != '\n' && c != EOF ){}
}
void printList(node **numbers)
{
  for( node *ptr = *numbers; ptr != NULL; ptr = ptr->next)
    {
      printf("%i\n",ptr->number);
    }
}
void deleteList(node **numbers)
{
  node *ptr = *numbers;
  while(ptr != NULL)
    {
      node *next = ptr->next;
      free(ptr);
      ptr = next;
    }
}

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

/********* DICTIONARY *********/
void printDictionary(dictionary **cover)
{
  dictionary *ptr = *cover;
  if( ptr != NULL )
    {
      for(int i=0;i<26;i++)
	{
	  if(ptr->letter[i] != NULL )
	    {
	      printf("%c",(char) i + 'A');
	    }
	  printDictionary(&ptr->letter[i]);
	}
      if( ptr->endword )
	{
	  printf("\n");
	}
    }
}
void deleteDictionary(dictionary **cover)
{
  dictionary *ptr = *cover;
  if( ptr != NULL )
    {
      for(int i=0; i<26;i++)
	{
	  deleteDictionary(&ptr->letter[i]);
	}
      free(ptr);
    }
}
