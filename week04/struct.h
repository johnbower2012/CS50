#ifndef __STRUCT_H__
#define __STRUCT_H__

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

/********* DICTIONARY *********/
typedef struct dictionary
{
  int endword;
  struct dictionary *letter[26];
}
dictionary;

void printDictionary(dictionary **cover);
void deleteDictionary(dictionary **cover);

#endif

