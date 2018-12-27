#include "linkedlist.h"

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

