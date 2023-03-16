#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  int y;
} Coord;

c;
x typedef struct {
  Coord firstPoint;
  Coord secondPoint;
} Rectangle;

typedef struct {
  char *name;
  int phoneNumber;
} Contact;

typedef struct {
  Contact *list;
  int amount;
} Contacts;

bool inRect(Coord dot, Rectangle rec) {
  if ((rec.secondPoint.x < dot.x && dot.x < rec.firstPoint.x) &&
      (rec.firstPoint.y < dot.y && dot.y < rec.secondPoint.y)) {
    return true;
  }
  return false;
}

void addContact(Contact *data) {
  char name[255];
  int phoneNumber;
  scanf("%s", name);
  scanf("%d", &phoneNumber);

  data->name = malloc(strlen(name) + 1);
  strcpy(data->name, name);
  data->name[strlen(data->name)] = '\0';
  data->phoneNumber = phoneNumber;
}

int addToContacts(Contact newContact, Contacts *agenda) {
  agenda->amount++;
  agenda->list = realloc(agenda->list, agenda->amount * sizeof(Contact));
  agenda->list[agenda->amount - 1] = newContact;
}

void showContacts(Contacts *agenda) {
  for (int i = 0; i < agenda->amount; i++) {
    printf("%s\n", agenda->list[i].name);
  }
}

int main() {
  Coord a = {0, 0}, b = {3, 3}, c = {4, 3};
  Rectangle rec;
  rec.firstPoint = a;
  rec.secondPoint = b;
  printf("%b\n", inRect(c, rec));

  Contact *con = malloc(sizeof(Contact));
  Contacts *agenda = malloc(sizeof(Contacts));
  agenda->amount = 0;
  agenda->list = NULL;

  addContact(con);
  printf("%s %d", con->name, con->phoneNumber);

  addToContacts(*con, agenda);
  showContacts(agenda);

  free(con->name);
  free(con);
  free(agenda->list);
  free(agenda);

  return 0;
}
