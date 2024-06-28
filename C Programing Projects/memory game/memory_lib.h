// memory_lib.h

#ifndef MEMORY_LIB_H
#define MEMORY_LIB_H

#include <stdio.h>  // for file handling
#include <stdlib.h>  // for dynamic memory allocation
#include <stdbool.h>  // for boolean data types
#include <string.h>  // for string manipulation (strlen, strcmp)
#include <time.h>  // for random number generation
#include <math.h>  // for mathematical operations

#define MAX_LETTERS 15  // maximum number of characters in a word

typedef struct {
    char word[MAX_LETTERS + 1];
    bool found;
} Card;

// Function prototypes
int countWords(const char *filename);
void loadCards(const char *filename, Card *cards, int size);
void shuffleCards(Card *cards, int size);
Card** createBoard(Card *cards, int size, int *rows, int *cols);
void getDimensions(int length, int *rows, int *cols);
void printBoard(Card **board, int rows, int cols);
bool checkVictory(Card **board, int rows, int cols);

#endif  // MEMORY_LIB_H
