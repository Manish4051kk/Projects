#ifndef BATTLESHIP_LIB_H
#define BATTLESHIP_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10

void initializeRandom();
void printMatrix(const char matrix[SIZE][SIZE]);
void buildBoard(char board[SIZE][SIZE], char character);
bool isWater(const char board[SIZE][SIZE], int row, int col);
void placeShipHorizontal(char board[SIZE][SIZE], int shipLength);
void placeShipVertical(char board[SIZE][SIZE], int shipLength);
void fillBoard(char board[SIZE][SIZE]);
void shoot(const char solution[SIZE][SIZE], char game[SIZE][SIZE], int row, int col);
bool checkVictory(const char solution[SIZE][SIZE], const char game[SIZE][SIZE]);

#endif // BATTLESHIP_LIB_H
