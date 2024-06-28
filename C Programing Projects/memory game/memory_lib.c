// Include the header file with prototypes and definitions
#include "memory_lib.h"  
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function: countWords
// Process: Reads a file and counts the number of words it contains (one word per line).
// Function input/parameters: filename (const char*): Name of the file to read.
// Function output/parameters: None.
// Function output/returned: int: The count of words in the file.
// Dependencies: stdio.h - fopen, fgets, fclose; string.h - strlen; stdlib.h - perror.
int countWords(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open file for reading
    if (file == NULL) { // Check if file opening failed
        printf("Error opening file");
        return 0; // Return 0 on error
    }

    int count = 0; // Initialize word count
    char word[MAX_LETTERS + 1]; // Buffer to store each word

    while (fgets(word, sizeof(word), file) != NULL) { // Read each line (word)
        count++; // Increment count
    }

    fclose(file); // Close the file
    return count; // Return the final word count
}

// Function: loadCards
// Process: Reads words from a file and initializes a given array of cards with those words.
// Function input/parameters: filename (const char*): Name of the file to read.
//                           cards (Card*): Pointer to the array of cards to populate.
//                           size (int): Number of cards to load.
// Function output/parameters: None.
// Function output/returned: None.
// Dependencies: stdio.h - fopen, fgets, fclose; string.h - strlen, snprintf; stdlib.h - perror.
void loadCards(const char *filename, Card *cards, int size) {
    FILE *file = fopen(filename, "r"); // Open file for reading
    if (file == NULL) { // Check if file opening failed
        printf("Error opening file");
        return; // Return early on error
    }

    int index = 0; // Index for cards array
    char word[MAX_LETTERS + 1]; // Buffer to store each word

    while (fgets(word, sizeof(word), file) != NULL && index < size) { // Read each line (word) and check index
        if (word[strlen(word) - 1] == '\n') { // Remove newline character if present
            word[strlen(word) - 1] = '\0';
        }

        // Initialize a new card with the read word and default found status
        Card newCard = {0};
        snprintf(newCard.word, sizeof(newCard.word), "%s", word);
        newCard.found = false;

        // Add the new card to the array, each word twice
        cards[index++] = newCard; // Add card to array
        cards[index++] = newCard; // Duplicate the card in array
    }

    fclose(file); // Close the file
    shuffleCards(cards, size); // Shuffle the cards after loading
}

// Function: shuffleCards
// Process: Randomly shuffles an array of cards.
// Function input/parameters: cards (Card*): Pointer to the array of cards to shuffle.
//                           size (int): Number of cards in the array.
// Function output/parameters: None.
// Function output/returned: None.
// Dependencies: stdlib.h - rand, srand; time.h - time.
void shuffleCards(Card *cards, int size) {
    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < size; i++) { // Loop through the array
        int j = rand() % size; // Generate a random index
        // Swap cards[i] with cards[j]
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

// Function: createBoard
// Process: Creates a 2D board from a 1D array of cards, setting proper dimensions.
// Function input/parameters: cards (Card*): Pointer to the array of cards to use.
//                           size (int): Number of cards in the 1D array.
//                           rows (int*): Pointer to an integer to store the number of rows.
//                           cols (int*): Pointer to an integer to store the number of columns.
// Function output/parameters: None.
// Function output/returned: Card**: Pointer to the created 2D board (dynamically allocated).
// Dependencies: stdlib.h - malloc; math.h - sqrt.
Card** createBoard(Card *cards, int size, int *rows, int *cols) {
    getDimensions(size, rows, cols); // Determine the appropriate dimensions for the board

    // Allocate memory for the 2D board
    Card **board = malloc(*rows * sizeof(Card*));
    for (int i = 0; i < *rows; i++) { // Allocate memory for each row
        board[i] = malloc(*cols * sizeof(Card));
    }

    int index = 0; // Index for the 1D card array
    for (int row = 0; row < *rows; row++) { // Fill the 2D board with the 1D cards
        for (int col = 0; col < *cols; col++) {
            if (index < size) { // Check if index is within bounds
                board[row][col] = cards[index]; // Assign card to board
                index++; // Increment index
            } else { // If beyond bounds, add an empty card
                Card emptyCard = {0}; // Initialize an empty card
                emptyCard.word[0] = '\0';  // Set word to empty string
                board[row][col] = emptyCard; // Assign empty card
            }
        }
    }

    return board; // Return the created 2D board
}

// Function: getDimensions
// Process: Determines the optimal row and column dimensions for a 2D board based on a given length.
// Function input/parameters: length (int): Length of the 1D array to determine the board dimensions.
//                           rows (int*): Pointer to store the calculated rows.
//                           cols (int*): Pointer to store the calculated columns.
// Function output/parameters: None.
// Function output/returned: None.
// Dependencies: math.h - sqrt.
void getDimensions(int length, int *rows, int *cols) {
    *rows = (int) sqrt(length);  // Start with square root for rows
    *cols = *rows;  // Initialize columns equal to rows

    // Adjust columns to ensure all elements fit on the board
    while ((*rows * *cols) < length) { 
        (*cols)++; // Increment columns until the product of rows and columns is at least equal to the length
    }
}

// Function: printBoard
// Process: Displays the content of a 2D board to the console.
// Function input/parameters: board (Card**): Pointer to the 2D board to print.
//                           rows (int): Number of rows in the board.
//                           cols (int): Number of columns in the board.
// Function output/parameters: None.
// Function output/returned: None.
// Dependencies: stdio.h - printf; string.h - strlen.
void printBoard(Card **board, int rows, int cols) {
    for (int row = 0; row < rows; row++) { // Iterate through each row
        for (int col = 0; col < cols; col++) { // Iterate through each column
            if (strlen(board[row][col].word) > 0) { // Check if the card is not empty
                if (board[row][col].found) { // If card is found, print its word
                    printf(" %s ", board[row][col].word);
                } else { // Otherwise, print masked card
                    printf(" *** ");
                }
            } else { // If the card is empty
                printf("     "); // Print empty space for empty card
            }
        }
        printf("\n"); // New line at the end of each row
    }
}

// Function: checkVictory
// Process: Checks if all cards on a 2D board have been found, indicating victory.
// Function input/parameters: board (Card**): Pointer to the 2D board to check.
//                           rows (int): Number of rows in the board.
//                           cols (int): Number of columns in the board.
// Function output/parameters: None.
// Function output/returned: bool: True if all cards are found, False if not.
// Dependencies: string.h - strlen.
bool checkVictory(Card **board, int rows, int cols) {
    for (int row = 0; row < rows; row++) { // Iterate through each row
        for (int col = 0; col < cols; col++) { // Iterate through each column
            if (strlen(board[row][col].word) > 0 && !board[row][col].found) { // If card is not empty and not found
                return false; // Return false if any card is not found
            }
        }
    }
    return true; // Return true if all cards are found
}
