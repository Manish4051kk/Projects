#ifndef TICTACTOE_LIB_H
#define TICTACTOE_LIB_H

#include <stdio.h> // Standard input/output
#include <stdbool.h> // Boolean data type

// Global constants for the Tic-Tac-Toe game
#define ROWS 3 // Total rows in the grid
#define COLS 3 // Total columns in the grid
#define PLAYER1_SYMBOL 'X' // Character for player1
#define PLAYER2_SYMBOL 'O' // Character for player2

// Function prototypes for the Tic-Tac-Toe library
void initializeBoard(char board[ROWS][COLS]); // Initialize the board with empty spaces
void displayBoard(const char board[ROWS][COLS]); // Display the current state of the board
bool isBoardFull(const char board[ROWS][COLS]); // Check if the board is full
bool checkWin(const char board[ROWS][COLS], char playerSymbol); // Check if a player has won
void play(); // Play the Tic-Tac-Toe game

#endif // TICTACTOE_LIB_H
