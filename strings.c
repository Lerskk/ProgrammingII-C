#include <stdio.h>
#include <stdlib.h>

int strlenTwo(char *string) {
	int i;
	for(i = 0; string[i] != '\0'; i++);
	return i;
}

char *  strcpyTwo(char *str) {
  char *newStr = NULL;
  for (int i = 0; str[i] != '\0'; i++) {
    newStr = realloc(newStr, i * sizeof(char));
    newStr[i] = str[i];
  }
  return newStr;
}

char *insertString() {
		char *input = NULL;
    int len = 0;
    int size = 1;
    char c;

    while ((c = getchar()) != '\n') {
        size += sizeof(char);
        input = (char*) realloc(input, size);
        input[len++] = c;
    }
    input = (char*) realloc(input, len + 1);
    input[len] = '\0';
		return input;
}

int main() {
	char stringOne[10] = "Hello lol", *stringTwo = NULL, *stringThree = insertString();
	printf("%d", strlenTwo(stringThree));
  char *newStr = strcpyTwo(stringThree);
  printf("%s", newStr);
  free(newStr);
	free(stringThree);
	return 0;
}