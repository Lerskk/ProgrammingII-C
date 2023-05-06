#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  int data;
  struct _Node *next;
} Node;

typedef Node *LinkedList;

LinkedList newList();

void printList(LinkedList list);

LinkedList addAtStart(LinkedList list, int data);

LinkedList addAtEnd(LinkedList list, int data);

int listLength(LinkedList list);

#endif
