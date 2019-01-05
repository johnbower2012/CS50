#include "stackqueue.h"

void push(stack *s, int *pushed)
{
  if(CAPACITY - 1 > s->top && s->top > -2 )
    {
      s->top++;
      s->array[s->top] = *pushed;
    }
  else
    {
      printf("Cannot push to stack. top marker, %i, out of proper range.\n",s->top);
    }
}

void pop(stack *s, int *popped)
{
  if(CAPACITY > s->top && s->top > -1)
    {
      *popped = s->array[s->top];
      s->top--;
    }
  else
    {
      printf("Cannot pop from stack. top marker, %i, out of proper range.\n",s->top);
    }
}

void testStack()
{
  int num;
  stack s;
  s.top = -1;
  printf("First element for stack: ");
  scanf("%i",&num);
  push(&s,&num);
  while( printf("Push (1) or Pop (0): ") && scanf("%i",&num) )
    {
      if( num == 1 )
	{
	  if(s.top < CAPACITY )
	    {
	      printf("  push: ");
	      scanf("%i",&num);
	      push(&s,&num);
	    }
	  else
	    {
	      printf("Cannot push to stack. Capacity reached: %i",(int) CAPACITY);
	    }
	}
      else if( num == 0 )
	{
	  if(s.top > -1)
	    {
	      pop(&s,&num);
	      printf("  popped: %i\n",num);
	    }
	  else
	    {
	      printf("Popped final element.\n");
	      break;
	    }
	}
      else
	{
	}
      printf("  elements: %i\n",s.top+1);      
    }
}
bool push_(stack_ **s, int *pushed)
{
  stack_ *n = (stack_ *)malloc(sizeof(stack_));
  if( n )
    {
      n->number = *pushed;
      n->next = NULL;
      if( !(*s) )
	{
	  *s = n;
	}
      else
	{
	  n->next = *s;
	  *s = n;
	}
      return true;
    }
  else
    {
      printf("Cannot allocate memory for new link.\n");
      return false;
    }
}

bool pop_(stack_ **s, int *popped)
{
  if( *s )
    {
      stack_ *ptr = *s;
      *popped = ptr->number;
      *s = ptr->next;
      free(ptr);
      return true;
    }
  else
    {
      printf("Cannot pop from an empty stack!\n");
      return false;
    }
}

void testStack_()
{
  int num;
  stack_ *s;
  printf("First element for stack: ");
  scanf("%i",&num);
  bool success = push_(&s,&num);
  while( (success && printf("Push (1) or Pop (0): ") && scanf("%i",&num) ) )
    {
      if( num == 1 )
	{
	  printf("  push: ");
	  scanf("%i",&num);
	  success = push_(&s,&num);
	}
      else if( num == 0 )
	{
	  if( (success = pop_(&s,&num)) )
	    {
	      printf("  popped: %i\n",num);
	    }
	}
    }
}
