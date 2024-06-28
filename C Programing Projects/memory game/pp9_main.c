#include "memory_lib.h"  // include the header file with function prototypes and definitions
#include <stdio.h>  // for standard input/output functions
#include <stdlib.h>  // for standard library functions
#include <string.h>  // for string comparison functions
#include <time.h>  // for time functions, needed for random seed

int main() {
    srand(time(NULL));  // seed the random number generator with current time

    printf("Welcome to the Memory Game!\n");  // display the game title to the user

    // Get the number of words in the file to determine the game size
    int numberOfWords = countWords("words.csv");  // call the function to count words in the CSV file
    if (numberOfWords == 0) {  // check if any words are present in the CSV file
        printf("No words found in the CSV file. Exiting...\n");  // inform the user and exit
        return 1;  // exit the program with a non-zero status indicating an error
    }

    int totalCards = numberOfWords * 2;  // total number of cards is twice the number of words

    Card *cards = (Card *)malloc(totalCards * sizeof(Card));  // allocate memory for the cards
    if (cards == NULL) {  // check if the memory allocation was successful
        perror("Error allocating memory");  // display an error message
        return 1;  // exit with error status due to memory allocation failure
    }

    loadCards("words.csv", cards, totalCards);  // load the words into the cards array from CSV file

    printf("Your current board contains %d pairs of cards.\n", numberOfWords);  // inform the user about the game setup

    int rows, cols;  // initialize variables for rows and columns
    Card **board = createBoard(cards, totalCards, &rows, &cols);  // create a 2D game board from the cards array
    printBoard(board, rows, cols);  // print the initial game board to the console

    int attempts = 0;  // initialize the number of attempts

    while (1) {  // infinite loop, broken when the game ends
        printf("Select the first card to reveal (row col): ");  // prompt for the first card input
        char buffer[10];  // buffer to store user input
        int firstRow, firstCol;  // declare variables for the row and column of the first card
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || strlen(buffer) == 1) {  // check if the input is empty
            printf("You gave up. See you next time!\n");  // notify the user that the game has ended
            break;  // exit the game loop
        }
        if (sscanf(buffer, "%d %d", &firstRow, &firstCol) != 2) {  // check if the input is valid
            printf("Invalid input. Game over.\n");  // invalid input scenario
            break;  // exit the game loop
        }

        // check if the selected card is within valid boundaries
        if (firstRow < 0 || firstRow >= rows || firstCol < 0 || firstCol >= cols) { 
            printf("Invalid card position. Try again.\n");  // invalid card position
            continue;  // continue to the next iteration
        }

        board[firstRow][firstCol].found = 1;  // mark the first card as found
        printBoard(board, rows, cols);  // print the game board with the first card revealed

        printf("Select the second card to reveal (row col): ");  // prompt for the second card input
        int secondRow, secondCol;  // declare variables for the row and column of the second card
        if (fgets(buffer, sizeof(buffer), stdin) == NULL || strlen(buffer) == 1) {  // check if the input is empty
            printf("You gave up. See you next time!\n");  // notify the user that the game has ended
            break;  // exit the game loop
        }
        if (sscanf(buffer, "%d %d", &secondRow, &secondCol) != 2) {  // check if the input is valid
            printf("Invalid input. Game over.\n");  // invalid input
            break;  // exit the game loop
        }

        // check if the second card is within valid boundaries
        if (secondRow < 0 || secondRow >= rows || secondCol < 0 || secondCol >= cols) { 
            printf("Invalid card position. Try again.\n");  // invalid card position
            continue;  // continue to the next iteration
        }

        board[secondRow][secondCol].found = 1;  // mark the second card as found
        printBoard(board, rows, cols);  // print the game board with both cards revealed

        attempts++;  // increment the attempts counter

        // check if the revealed cards do not match
        if (strcmp(board[firstRow][firstCol].word, board[secondRow][secondCol].word) != 0) { 
            board[firstRow][firstCol].found = 0;  // reset found status for the first card
            board[secondRow][secondCol].found = 0;  // reset found status for the second card
            printf("Cards do not match. Press Enter to continue...");  // instruct the user to press Enter
            getchar();  // wait for the user to press enter to proceed  // ensure the new line is consumed

            // Clear the console for cross-platform compatibility
            #ifdef _WIN32
            system("cls");  // Windows-specific command to clear the console
            #else
            system("clear");  // command to clear the console in Unix-like systems
            #endif

            printBoard(board, rows, cols);  // reprint the game board with updated card visibility
        }

        // check if all pairs are found, indicating victory
        if (checkVictory(board, rows, cols)) {
            printf("Congratulations! You have won the game with %d attempts.\n", attempts);  // congratulate the player
            break;  // exit the game loop
        }
    }

    // Deallocate the memory used by the 2D board
    for (int i = 0;  // loop through each row
         i < rows;  // condition for loop
         i++) {  // increment i after each loop
        free(board[i]);  // free the memory for each row
    }
    free(board);  // free the 2D board array
    free(cards);  // free the card array

    printf("Program has ended successfully.\n");  // message indicating successful program termination

    return 0;  // return zero to indicate successful program execution
}
