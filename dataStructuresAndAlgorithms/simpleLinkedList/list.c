#include "list.h"
#include <stdlib.h>

LinkedList newList() { return NULL; }

void printList(LinkedList list) {
  for (; list != NULL; list = list->next)
    printf("%d %p\n", list->data, list->next);
}

LinkedList addAtStart(LinkedList list, int data) {
  Node *newNode = malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = list;

  return newNode;
}

LinkedList addAtEnd(LinkedList list, int data) {
  Node *newNode = malloc(sizeof(Node));

  newNode->data = data;
  newNode->next = NULL;

  LinkedList node = list;

  for (; node->next != NULL; node = node->next)
    ;

  node->next = newNode;
  return list;
}

int listLength(LinkedList list) {
  if (list == NULL) {
    return 0;
  }
  int counter = 1;
  for (; list->next != NULL; counter++, list = list->next)
    ;
  return counter;
}
