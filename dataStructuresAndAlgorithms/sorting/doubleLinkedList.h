#ifndef __DOUBLE_LINKED_LIST__
#define __DOUBLE_LINKED_LIST__

typedef struct _Node {
  int data;
  struct _Node *next;
  struct _Node *prev;
} Node;

typedef Node *DoubleLinkedList;

DoubleLinkedList addAtStart(DoubleLinkedList list, int data);

void printList(DoubleLinkedList list);

#endif
