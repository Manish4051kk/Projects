#ifndef HANGMAN_LIB_H
#define HANGMAN_LIB_H

#include <stdbool.h>

// Define the length of the array of fruits
#define LEN_FRUITS 120

// Define the maximum number of tries allowed
#define MAX_TRIES 6

// Define the maximum length of a word
#define MAX_WORD_LENGTH 20

// Define the maximum number of unique letters that can be guessed
#define MAX_GUESSED_LETTERS 26 

// Array of fruits
extern const char* FRUITS[LEN_FRUITS];

// Function prototypes
void printWelcomeMessage(); 
bool play(bool* giveup); 
void initializeRandom(); 
int getSecretWord(char* secretWord); 
void buildOutputArray(int length, char* outputArray); 
void buildAttemptArray(char* attemptArray); 
bool checkGuess(char guess, const char* secretWord); 
bool fillOutputArray(char guess, const char* secretWord, char* outputArray); 
bool fillAttemptsArray(char guess, char* attemptArray); 
bool checkVictory(const char* outputArray, int length); 
bool checkDefeat(const char* attemptArray); 

#endif /* HANGMAN_LIB_H */
