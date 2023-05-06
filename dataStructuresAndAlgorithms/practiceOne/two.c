#include <stdio.h>
#include <stdlib.h>

int stringLength(char *arr) {
  int length;

  for (length = 0; arr[length] != '\0'; length++)
    ;
  return length;
}

void reverseString(char *arr) {
  int i, length = stringLength(arr);
  char *reverse = NULL;

  for (i = 0; i < length; i++) {
    reverse = realloc(reverse, sizeof(char) * (i + 1));
    printf("%d %d \n", i, length);
    reverse[i] = arr[length - i - 1];
  }
  reverse[i] = '\0';

  for (i = 0; i < length; i++) {
    printf("%c", reverse[i]);
  }

  free(reverse);
}
int main() {
  char *arr = "hello";
  reverseString(arr);
  return 0;
}
