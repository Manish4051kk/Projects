#include "battleship_lib.h"

/**
* Name: initializeRandom
* Process: Initializes the random number generator using the current time as seed.
* Function input/parameters: None
* Function output/parameters: None
* Function output/returned: None
* Dependencies: Requires inclusion of <time.h> header file.
**/
void initializeRandom() {
    srand((unsigned int)time(NULL));
}

/**
* Name: printMatrix
* Process: Prints the contents of a matrix to the console.
* Function input/parameters: matrix - a 2D array representing the matrix to be printed.
* Function output/parameters: None
* Function output/returned: None
* Dependencies: Requires inclusion of <stdio.h> header file.
**/
void printMatrix(const char matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
* Name: buildBoard
* Process: Initializes the elements of a matrix with a specified character.
* Function input/parameters: board - a 2D array representing the board to be initialized,
*                           character - the character to initialize the board with.
* Function output/parameters: None
* Function output/returned: None
* Dependencies: None
**/
void buildBoard(char board[SIZE][SIZE], char character) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = character;
        }
    }
}

/**
* Name: isWater
* Process: Checks if a given cell in the board contains water ('0').
* Function input/parameters: board - a 2D array representing the board,
*                            row - the row index of the cell to check,
*                            col - the column index of the cell to check.
* Function output/parameters: None
* Function output/returned: Returns true if the cell contains water, false otherwise.
* Dependencies: None
**/
bool isWater(const char board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
    return board[row][col] == '0';
}

/**
* Name: placeShipHorizontal
* Process: Places a ship horizontally on the board.
* Function input/parameters: board - a 2D array representing the board,
*                            shipLength - length of the ship to be placed.
* Function output/parameters: None
* Function output/returned: None
* Dependencies: Depends on isWater() function.
**/
void placeShipHorizontal(char board[SIZE][SIZE], int shipLength) {
    int row = rand() % SIZE;
    int col;
    do {
        col = rand() % (SIZE - shipLength + 1);
    } while (!isWater(board, row, col));

    for (int i = 0; i < shipLength; i++) {
        board[row][col + i] = (char)(shipLength + '0');
    }
}

/**
* Name: placeShipVertical
* Process: Places a ship vertically on the board.
* Function input/parameters: board - a 2D array representing the board,
*                            shipLength - length of the ship to be placed.
* Function output/parameters: None
* Function output/returned: None
* Dependencies: Depends on isWater() function.
**/
void placeShipVertical(char board[SIZE][SIZE], int shipLength) {
    int col = rand() % SIZE;
    int row;
    do {
        row = rand() % (SIZE - shipLength + 1);
    } while (!isWater(board, row, col));

    for (int i = 0; i < shipLength; i++) {
        board[row + i][col] = (char)(shipLength + '0');
    }
}

/**
* Name: fillBoard
* Process: Fills the board with ships of varying lengths.
* Function input/parameters: board - a 2D array representing the board.
* Function output/parameters: None
* Function output/returned: None
* Dependencies: Depends on placeShipHorizontal() and placeShipVertical() functions.
**/
void fillBoard(char board[SIZE][SIZE]) {
    int ships[] = {5, 4, 4, 3, 3, 3, 2, 2, 2, 2};
    for (int i = 0; i < 10; i++) {
        int orientation = rand() % 2;
        if (orientation == 0) {
            placeShipHorizontal(board, ships[i]);
        } else {
            placeShipVertical(board, ships[i]);
        }
    }
}

/**
* Name: shoot
* Process: Updates the game board based on the shot fired.
* Function input/parameters: solution - a 2D array representing the solution board,
*                            game - a 2D array representing the player's board,
*                            row - the row index of the shot fired,
*                            col - the column index of the shot fired.
* Function output/parameters: None
* Function output/returned: None
* Dependencies: None
**/
void shoot(const char solution[SIZE][SIZE], char game[SIZE][SIZE], int row, int col) {
    if (solution[row][col] != '0') {
        game[row][col] = 'S';
    } else {
        game[row][col] = 'W';
    }
}

/**
* Name: checkVictory
* Process: Checks if the player has won the game.
* Function input/parameters: solution - a 2D array representing the solution board,
*                            game - a 2D array representing the player's board.
* Function output/parameters: None
* Function output/returned: Returns true if all ships are sunk, false otherwise.
* Dependencies: None
**/
bool checkVictory(const char solution[SIZE][SIZE], const char game[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (solution[i][j] != '0' && game[i][j] != 'S') {
                return false;
            }
        }
    }
    return true;
}
