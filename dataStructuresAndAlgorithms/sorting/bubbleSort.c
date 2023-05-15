#include "doubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

DoubleLinkedList bubbleSort(DoubleLinkedList list) {
  int didSomething = 1;
  Node *firstNode = NULL, *first = NULL, *second = NULL,
       *surroundingLeft = NULL, *surroundingRight = NULL;
  while (didSomething) {
    didSomething = 0;
    firstNode = list;
    do {
      first = list;
      second = list->next;
      surroundingLeft = first->prev;
      surroundingRight = second->next;
      if (first->data > second->data) {
        // surrounding nodes
        first->prev->next = second;
        second->next->prev = first;

        first->prev = second;
        second->next = first;

        first->next = surroundingRight;
        second->prev = surroundingLeft;
        didSomething = 1;
        list = list->next;
      }
    } while (list->next != firstNode);
  }

  free(surroundingLeft);
  free(surroundingRight);

  return list;
}

int main() {
  DoubleLinkedList list = NULL;

  list = addAtStart(list, 3);
  list = addAtStart(list, 1);
  list = addAtStart(list, 2);

  printList(list);

  list = bubbleSort(list);

  printList(list);
  return 0;
}
