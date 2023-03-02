#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *surName;
  int age;
  char *location;
} Person;

// data design
// given a specific file name and a person represented by the struct Person

// signature and function purpose
// appendPerson: char* -> Person -> NULL
// the function will append to the file the data of the person split it by ,
// and it puts a enter at the end
void appendPerson(char *saveLocation, Person *person) {
  FILE *saveFile = fopen(saveLocation, "a");

  fprintf(saveFile, "%s,", person->name);
  fprintf(saveFile, "%s,", person->surName);
  fprintf(saveFile, "%d,", person->age);
  fprintf(saveFile, "%s\n", person->location);

  fclose(saveFile);
}

void readString(char **stringLocation) {
  int i, c;
  for (i = 0; (c = getchar()) != '\n'; i++) {
    *stringLocation = realloc(*stringLocation, sizeof(char) * (i + 1));
    (*stringLocation)[i] = c;
  }
  *stringLocation = realloc(*stringLocation, sizeof(char) * (i + 1));
  (*stringLocation)[i] = '\0';
}

Person createPerson(char *name, char *surName, int age, char *location) {
  Person person = {name, surName, age, location};
  return person;
}

void registerPerson() {
  char *name = NULL, *surName = NULL, *location = NULL;
  int age;
  printf("Getting human...\n");
  printf("Human name: ");
  readString(&name);

  printf("Human sur name: ");
  readString(&surName);

  printf("Human age: ");
  scanf("%d", &age);
  getchar();

  printf("Human location: ");
  readString(&location);

  Person person = {name, surName, age, location};
  appendPerson("saveFile.txt", &person);

  free(name);
  free(surName);
  free(location);
}

int main() {
  Person person = {"Fausto", "Leoni", 20, "Rosario"};
  registerPerson();
  appendPerson("saveFile.txt", &person);
  registerPerson();
  appendPerson("saveFile.txt", &person);
  return 0;
}
