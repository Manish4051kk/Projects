//header file
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "battleship_lib.h"

#define BOARD_SIZE 10

//main program
int main() {
    // Part I - Setup
    srand(time(NULL)); // Initialize seed for random number generator

    char solution_board[BOARD_SIZE][BOARD_SIZE];
    char game_board[BOARD_SIZE][BOARD_SIZE];

    // Initialize game boards
    buildBoard(solution_board, '0');
    buildBoard(game_board, '_');

    // Place ships on the solution board
    fillBoard(solution_board);

    printf("Battleship Game\n===============\n\n");

    // Print initial game board
    printf("Game board:\n");
    printMatrix(game_board);

    // Part II - the game
    int row, col;
    while (1) {
        // Prompt user for coordinates
        printf("Enter the ROW (0-9) where you want to shoot or -1 to give up: ");
        scanf("%d", &row);
        if (row == -1) {
            // User gives up, print solution board and exit loop
            printf("You gave up. Here is the solution board:\n");
            printMatrix(solution_board);
            break;
        }
        // Validate input
        if (row < 0 || row >= BOARD_SIZE) {
            printf("Invalid input. Please enter a number between 0 and 9.\n");
            continue;
        }
        printf("Enter the COLUMN (0-9) where you want to shoot or -1 to give up: ");
        scanf("%d", &col);
        if (col == -1) {
            // User gives up, print solution board and exit loop
            printf("You gave up. Here is the solution board:\n");
            printMatrix(solution_board);
            break;
        }
        // Validate input
        if (col < 0 || col >= BOARD_SIZE) {
            printf("Invalid input. Please enter a number between 0 and 9.\n");
            continue;
        }

        // Shoot at the position given by the user
        shoot(solution_board, game_board, row, col);

        // Check the result of the shot
        if (game_board[row][col] == 'S') {
            printf("Ship!\n");
        } else {
            printf("Miss!\n");
        }

        // Print current status
        printf("Current game board:\n");
        printMatrix(game_board);

        // Check if the user won
        if (checkVictory(solution_board, game_board)) {
            printf("Congratulations! You sank all the ships!\n");
            break;
        }
    }

    return 0;
}
