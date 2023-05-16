#include "doubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

DoubleLinkedList *addAtStart(DoubleLinkedList *list, int data) {
  Node *newNode = malloc(sizeof(Node));
  if (list->head == NULL) {
    newNode->next = newNode;
    newNode->prev = newNode;
    newNode->data = data;
    list->head = newNode;
    list->tail = newNode;
    return list;
  }

  newNode->next = list->head;
  newNode->prev = list->tail;
  newNode->data = data;

  list->head->prev = newNode;
  list->head = newNode;
  list->tail->next = newNode;

  return list;
}

void printList(DoubleLinkedList *list) {
  if (list->head == NULL)
    return;
  Node *currentNode = list->head;

  do {
    printf("%p %p %p %d\n", currentNode->prev, currentNode, currentNode->next,
           currentNode->data);
    currentNode = currentNode->next;
  } while (currentNode != list->head);
}
