// Including header file for Hangman game
#include "hangman_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* List of fruits as secret words */
const char* FRUITS[LEN_FRUITS] = {"abiu", "acai", "acerola", "akebi", "ackee",
                                   "apple", "apricot", "araza", "avocado", "banana", "bilberry", "blackberry",
                                   "blackcurrant", "blueberry", "boysenberry", "breadfruit", "canistel",
                                   "cashew", "cempedak", "cherimoya", "cherry", "cloudberry", "coconut",
                                   "cranberry", "currant", "damson", "date", "dragonfruit", "pitaya", "durian",
                                   "elderberry", "feijoa", "fig", "gooseberry", "grape", "raisin",
                                   "grapefruit", "guava", "honeyberry", "huckleberry", "jabuticaba", "plinia",
                                   "jackfruit", "jambul", "jostaberry", "jujube", "kiwano", "kiwifruit",
                                   "kumquat", "lemon", "lime", "loganberry", "longan", "loquat", "lulo",
                                   "lychee", "mango", "mangosteen", "marionberry", "melon", "cantaloupe",
                                   "galia", "melon", "honeydew", "watermelon", "mulberry", "nance",
                                   "nectarine", "orange", "clementine", "mandarine", "tangerine", "papaya",
                                   "passionfruit", "pawpaw", "peach", "pear", "persimmon", "plantain", "plum",
                                   "prune", "pineapple", "pineberry", "plumcot", "pluot", "pomegranate",
                                   "pomelo", "quince", "raspberry", "salmonberry", "rambutan", "redcurrant",
                                   "salak", "sapodilla", "sapote", "satsuma", "soursop", "strawberry",
                                   "tamarillo", "tamarind", "tangelo", "tayberry", "ximenia", "yuzu"};

// Function to print welcome message
void printWelcomeMessage() {
    printf("***************************\n");
    printf("Welcome to the Hangman Game\n");
    printf("***************************\n");
}

// Function to choose a random word from the FRUITS array
int chooseWord(char* word) {
    srand(time(NULL));
    int index = rand() % LEN_FRUITS;
    strcpy(word, FRUITS[index]);
    return strlen(word);
}

// Function to initialize random seed
void initializeRandom() {
    srand((unsigned int)time(NULL)); // Casting to unsigned int for compatibility
}

// Function to get a secret word
int getSecretWord(char* secretWord) {
    int index = rand() % LEN_FRUITS;
    strcpy(secretWord, FRUITS[index]);
    return (int)strlen(secretWord); // Casting to int for consistency
}

// Function to initialize the output array with underscores
void buildOutputArray(int length, char* outputArray) {
    for (int i = 0; i < length; i++) {
        outputArray[i] = '_';
    }
    outputArray[length] = '\0';
}

// Function to initialize the attempt array with asterisks
void buildAttemptArray(char* attemptArray) {
    for (int i = 0; i < MAX_TRIES; i++) {
        attemptArray[i] = '*';
    }
    attemptArray[MAX_TRIES] = '\0';
}

// Function to check if a guessed letter is in the secret word
bool checkGuess(char guess, const char* secretWord) {
    for (const char* ptr = secretWord; *ptr != '\0'; ptr++) {
        if (*ptr == guess) {
            return true;
        }
    }
    return false;
}

// Function to fill the output array with correctly guessed letters
bool fillOutputArray(char guess, const char* secretWord, char* outputArray) {
    bool found = false;
    for (int i = 0; secretWord[i] != '\0'; i++) {
        if (secretWord[i] == guess && outputArray[i] == '_') {
            outputArray[i] = guess;
            found = true;
        }
    }
    return found;
}

// Function to fill the attempts array with guessed letters
bool fillAttemptsArray(char guess, char* attemptArray) {
    for (int i = 0; i < MAX_TRIES; i++) {
        if (attemptArray[i] == '*') {
            attemptArray[i] = guess;
            return true;
        }
    }
    return false;
}

// Function to check if the player has won
bool checkVictory(const char* outputArray, int length) {
    for (int i = 0; i < length; i++) {
        if (outputArray[i] == '_') {
            return false;
        }
    }
    return true;
}

// Function to check if the player has lost
bool checkDefeat(const char* attemptArray) {
    for (int i = 0; i < MAX_TRIES; i++) {
        if (attemptArray[i] == '*') {
            return false;
        }
    }
    return true;
}

// Function to play the Hangman game
bool play(bool* giveup) {
    *giveup = false;
    char word[MAX_WORD_LENGTH];
    int len = chooseWord(word);
    char guessed[MAX_WORD_LENGTH];
    for (int i = 0; i < len; i++) {
        guessed[i] = '_';
    }
    guessed[len] = '\0';
    char mistakes[MAX_TRIES + 1];
    mistakes[0] = '\0';
    int mistakesCount = 0;
    bool won = false;
    char guessedLetters[MAX_GUESSED_LETTERS]; // Array to keep track of guessed letters
    int guessedLetterIndex = 0;

    while (mistakesCount < MAX_TRIES) {   
        printf("\nWhich letter? (0 to exit the game): \n");
        char guess;
        scanf(" %c", &guess);
        if (guess == '0') {
            *giveup = true;
            break;
        }
        
        // Check if the guessed letter has already been guessed
        bool repeatedGuess = false;
        for (int i = 0; i < guessedLetterIndex; i++) {
            if (guessedLetters[i] == guess) {
                repeatedGuess = true;
                break;
            }
        }
        
        if (repeatedGuess) {
            printf("Repeated guess. Try another letter!\n");
            continue; // Prompt again for input
        }
        
        guessedLetters[guessedLetterIndex++] = guess;

        bool found = false;
        for (int i = 0; i < len; i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                found = true;
            }
        }
        printf("\n%s\n\n", guessed);
        if (!found) {
            mistakes[mistakesCount++] = guess;
            mistakes[mistakesCount] = '\0';
            printf("The letter doesn't exist in the word.\n");
            printf("Mistakes: %s\n", mistakes);
        }
        if (strcmp(word, guessed) == 0) {
            won = true;
            printf("%s\n", word); // Revealing the word
            break;
        }
    }
    if (!won && !*giveup) {
        printf("The secret word was: %s\n", word);
    }
    return won;
}

