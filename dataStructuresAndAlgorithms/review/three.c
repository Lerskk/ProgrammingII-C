#include <stdio.h>
#include <stdlib.h>

void setIn(int *ptr) {
  if (ptr == NULL) {
    printf("Error, pointer is NULL");
    return;
  }
  if (*ptr != 0)
    *ptr = 1;
}

int main() {
  int *ptr = NULL;
  ptr = malloc(sizeof(int));

  *ptr = 2121;
  setIn(ptr);

  *ptr = 0;
  setIn(ptr);

  free(ptr);
  return 0;
}
