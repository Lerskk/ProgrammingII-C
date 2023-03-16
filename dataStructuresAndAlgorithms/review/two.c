#include <stdio.h>

void setFirst(int arr[]) { arr[0] = 0; }

int main() {
  int arr[3];
  arr[0] = 1;

  for (int i = 0; i < 3; i++)
    printf("%d ", arr[i]);
  printf("\n");

  setFirst(arr);

  for (int i = 0; i < 3; i++)
    printf("%d ", arr[i]);

  printf("\n");
  return 0;
}
