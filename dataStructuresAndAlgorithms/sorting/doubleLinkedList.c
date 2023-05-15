#include "doubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

DoubleLinkedList addAtStart(DoubleLinkedList list, int data) {
  Node *newNode = malloc(sizeof(Node));
  if (list == NULL) {
    newNode->next = newNode;
    newNode->prev = newNode;
    newNode->data = data;
    return newNode;
  }

  newNode->next = list;
  newNode->prev = list->prev;
  newNode->data = data;

  list->prev->next = newNode;
  list->prev = newNode;

  return newNode;
}

void printList(DoubleLinkedList list) {
  if (list == NULL)
    return;
  Node *firstNode = list;
  Node *currentNode = list;

  do {
    printf("%p %p %p %d\n", currentNode->prev, currentNode, currentNode->next,
           currentNode->data);
    currentNode = currentNode->next;
  } while (currentNode != firstNode);
}
