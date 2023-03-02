#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// data design
//
// signature and purpose declaration
// examples 
//
char generateBoardToken() {
  int opt = rand() % 3;  

  switch (opt) {
    case 0: 
      return '0';
    case 1: 
      return '1';
    case 2: 
      return '_';
  }
  return '\0';
}


// #data design
// lengt and height of the board represented by ints

// #signature and function purpose
// generateBoard: int -> int -> char**
// given a certain length and height the function will generate a board and it will give
// on each cell a token between (0, 1, _) witch represent the player 0, 1 and in case that
// there is no token will be a _

// #examples
// input: 5 6 output:
// 1101_1
// 1001_1
// _1_100
// 11__00
// ___111




char **generateBoard(int length, int height) {
  char **board = malloc(sizeof(char*) * length + 1);
  int i, j;
  
  
  for (i = 0; i < length; i++) {
    board[i] = malloc(sizeof(char) * height + 1);
    for (j = 0; j < height; j++) {
      board[i][j] = generateBoardToken();
    }
    board[i][j] = '\0';
  }
  board[i] = NULL;
  return board;
} 

void displayBoard(char **board, int length, int height) {
  for (int i = 0; board[i] != NULL; i++) {
    for (int j = 0; board[i][j] != '\0'; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// data design
// a file name is represented by a pontier to a char (string) and a pointer to a pointer (bidemintional array)
// represents the board (length and width)

// signature and function purpose
// saveGame: char* -> char** -> None
// given a file name it will write the content of board row by row in the file location

void saveGame(char* saveLocation, char **board) {
  FILE *file = fopen(saveLocation, "w");

  for (int i = 0; board[i] != NULL; i++) {
    fprintf(file, "%s\n", board[i]);
  }

  fclose(file);
}

int main() {
  int boardLength = 0, boardHeight;
  while (boardLength < 4) {
    printf("Waiting for board length... (must be more than 3): ");
    scanf("%d", &boardLength);
    boardHeight = boardLength + 1;
  }

  char **board = generateBoard(boardLength, boardHeight), *saveLocation ="save.txt";
  displayBoard(board, boardLength, boardHeight);

  saveGame(saveLocation, board);

  for (int i = 0; board[i] != NULL; i++) {
    free(board[i]);
  }
  free(board);
}
