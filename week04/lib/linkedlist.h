#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* LINKED LIST *********/
typedef struct node
{
  int number;
  struct node *next;
} 
node;

void buildList(node **numbers);
void appendList(node **numbers);
void printList(node **numbers);
void deleteList(node **numbers);

#endif
