#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initRandom() {
  srand(time(NULL));
}

int getRandomNumber(int min, int max) {
  int randomNumber = rand() % (max - min + 1) + min;
  return randomNumber;
}

void printRandomNumber() {
  int randomNumber = getRandomNumber(1, 10);
  printf("Random number: %d\n", randomNumber);
}

void printTwoRandomNumbers() {
  int randomNumber1 = getRandomNumber(1, 10);
  int randomNumber2 = getRandomNumber(1, 10);

  printf("Random number 1: %d\n", randomNumber1);
  printf("Random number 2: %d\n", randomNumber2);
}

int main() {
  initRandom();

  printRandomNumber();
  printTwoRandomNumbers();

  return 0;
}
