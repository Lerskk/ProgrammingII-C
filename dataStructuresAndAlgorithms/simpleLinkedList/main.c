#include "list.h"

int main() {
  LinkedList list = newList();

  printf("length: %d\n", listLength(list));
  list = addAtStart(list, 0);
  printf("length: %d\n", listLength(list));
  list = addAtStart(list, 1);
  printf("length: %d\n", listLength(list));
  list = addAtEnd(list, -1);
  printf("length: %d\n", listLength(list));
  printList(list);

  return 0;
}
