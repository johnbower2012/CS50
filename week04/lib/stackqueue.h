#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 20

//LIFO
typedef struct stack
{
  int array[CAPACITY];
  int top;
}
stack;

//LIFO
typedef struct stack_
{
  int number;
  struct stack_ *next;
}
stack_;

void push(stack *s, int *pushed);
void pop(stack *s, int *popped);
void testStack();

bool push_(stack_ **s, int *pushed);
bool pop_(stack_ **s, int *popped);
void testStack_();

#endif
