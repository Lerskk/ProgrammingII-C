#include <stdio.h>
int main() {
  char *ptr = " hola mundo ";
  printf(" %s \n ", ptr);
  ptr[0] = 's';
  printf(" %s \n ", ptr);
  return 0;
}
