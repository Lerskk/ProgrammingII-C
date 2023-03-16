#include <stdio.h>
int main() {
  int a, b, c = 5, array[] = {1, 2, 8, 6};
  printf("%p %p %p\n\n", &a, &b, &c);

  int size = sizeof(array) / sizeof(int);
  for (int i = 0; i < size; i++)
    printf("%d: %p\n", i, &array[i]);
  return 0;
}
