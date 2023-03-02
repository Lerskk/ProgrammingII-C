#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generateRandomNumber(int min, int max) {
  int randomNumber = rand() % (max - min + 1) + min;
  return randomNumber;
}

void getDimensions(FILE *saveFile) {
  int length, width;
  printf("Board width: ");
  scanf("%d", &width);

  printf("Board length: ");
  scanf("%d", &length);

  // check if length and width are between 10 and 20
  while (!(10 < length && length < 20) || !(10 < width && width < 20)) {
    printf("ERROR: Both inputs must be between 10 and 20\n");
    printf("Board width: ");
    scanf("%d", &width);

    printf("Board length: ");
    scanf("%d", &length);
  }

  // write width and length on file
  fprintf(saveFile, "%d %d\n", width, length);
}

bool testBoat(int **fleet, int boardWidth, int boardLength,int x, int y, int orientation, int length) {
  for (int i = 0; i < length; i++) {
      if ((orientation == 0) && !((*(*(fleet+x+i)+y))== 0))
        return false;

      if ((orientation == 1) && !((*(*(fleet+x)+y+i)) == 0))
        return false;
  }
  return true;
}

void generateBoat(FILE *saveFile, int **fleet, int boardWidth, int boardLength) {
  int *boat = malloc(sizeof(int) * 4), x, y;

  boat[2] = generateRandomNumber(0, 1);
  boat[3] = generateRandomNumber(2, 4);


  bool valid = false;

  while (!valid) {
    if (boat[2] == 0) {
      x = generateRandomNumber(0, boardWidth - 1 - boat[3]);
      y = generateRandomNumber(0, boardLength - 1);

    }
    if (boat[2] == 1) {
      x = generateRandomNumber(0, boardWidth - 1);
      y = generateRandomNumber(0, boardLength - 1 - boat[3]);
    }

    valid = testBoat(fleet, boardWidth, boardLength, x, y, boat[2], boat[3]);
    if (valid) { 
      for (int i = 0; i < boat[3]; i++) {
        if (boat[2] == 0) 
          *(*(fleet+x+i)+y) = 1;

        if (boat[2] == 1) 
          *(*(fleet+x)+y+i) = 1;
      }
      fprintf(saveFile, "%d %d %d %d\n", x, y, boat[2], boat[3]);
    }
  }
}

int **generateEmptyFleet(int width, int length) {
  int **fleet = malloc(sizeof(int*) * (width + 1)), i, j;
  for (i = 0; i < width; i++) {
    *(fleet+i) = malloc(sizeof(int) * (length + 1));
    for (j = 0; j < length; j++) {
      *(*(fleet+i)+j) = 0;
    }
    *(*(fleet+i)+j) = -1;
  }
  *(fleet+i) = NULL;
  return fleet;
}

void initSeed() {
  srand(time(NULL));
}


void generateFleet(FILE *saveFile) {
  time_t t;
  srand(t);

  char *length = malloc(sizeof(char) * 2), *width = malloc(sizeof(char) * 2);
  fseek(saveFile, 0, SEEK_SET);


  fscanf(saveFile, "%[^' ']", length);
  fgetc(saveFile);
  fscanf(saveFile, "%[^' ']", width);

  initSeed();
  int **fleet = generateEmptyFleet(atoi(width), atoi(length)), boatNumber, amountOfBoats = generateRandomNumber(0, 51);
  printf("boats %d\n", amountOfBoats);

  for (boatNumber = 0; boatNumber < amountOfBoats; boatNumber++) {
    generateBoat(saveFile, fleet, atoi(length), atoi(width));
  }

}

int main() {
  initSeed();

  FILE *saveFile = fopen("save.txt", "w+");
  getDimensions(saveFile);
  generateFleet(saveFile);

  fclose(saveFile);
}


// how to make the algorithm to check if boat
// generate a boat array, with 1 for boat and 0 for not
