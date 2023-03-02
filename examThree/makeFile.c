#include <stdio.h>
#include <stdlib.h>

int countLines(FILE *file) {
  int c, lines = 0;

  for (; (c = fgetc(file)) != EOF;) {
    if (c == '\n') {
      lines++;
    }
  };

  return lines;
}

void writeLines(FILE *file,FILE *output) {
  int lines = countLines(file);

  fprintf(output, "%d\n", lines);
  fseek(file, 0, SEEK_SET);
}

void readLine(FILE *file, char **string) {
  char i, c; 

  *string = NULL;
  for(i = 0; (c = fgetc(file)) != '\n'; i++) {
    *string = realloc(*string, sizeof(char) * (i + 1));
    (*string)[i] = c;
  }
  *string = realloc(*string, sizeof(char) * (i + 1));
  (*string)[i] = '\n';
}

int writeAntonyms(FILE *fileOne, FILE *fileTwo, FILE *output) {
  char *line = NULL;
  int c = fgetc(fileOne), firstExist = 0, secondExist = 0;

  if (c != '\n') {
    ungetc(c, fileOne);
    readLine(fileOne, &line);
    fprintf(output, "%s", line);
    firstExist = 1;
  }
  
  c = fgetc(fileTwo);
  if (c != '\n') {
    ungetc(c, fileTwo);
    readLine(fileTwo, &line);
    fprintf(output, "%s", line);
    secondExist = 1;
  } 

  if (firstExist + secondExist == 2) 
    return 1;
  return 0;
}

void writeThings(FILE *fileOne, FILE *fileTwo, FILE *output) {
  char *line = NULL;
  int c, *relation = NULL, relationAmounts = 0;

  for(int i = 0; (c = fgetc(fileOne)) != EOF; i++) {
    ungetc(c, fileOne);

    relationAmounts++;
    relation = realloc(relation, sizeof(int) * relationAmounts);
    relation[relationAmounts - 1] = writeAntonyms(fileOne, fileTwo, output);
  }
  int a = 0;
  for(int i = 1; i <= relationAmounts; i++) {
    if (relation[i - 1] == 1) {
      fprintf(output, "%d %d\n", a + i + 1,  a + i + 2);
    } else
      a++;
  }
}

int main() {
  FILE *file = fopen("fileOne.txt", "r"), *fileTwo = fopen("fileTwo.txt", "r"), *output = fopen("output.txt", "w");
  writeLines(file, output);
  writeThings(file, fileTwo, output);
  return 0;
}
