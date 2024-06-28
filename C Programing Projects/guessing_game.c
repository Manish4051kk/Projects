/*
Lab 3 - Problem 2: guessing game
Driver: <driver's name> (<driver's student id>)
Navigator: <navigator's name> (navigator's student id)
*/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant declaration
#define MAXNUMBER 20

// prototypes
int generateRandomNumber(int a);

// main program
int main()
{
    // initialize the program
    // declare user input variables
    int randomNumber, playerGuess;

    // show title
    //function: printf
    printf("Welcome to the Guessing Game!\n");
    printf("Try to guess the number between 1 and %d.\n",MAXNUMBER);
    printf("==================================================\n");

    // Generate a random number
    // function: generateRandomNumber
    randomNumber = generateRandomNumber(MAXNUMBER);

    // Get user input and process the data
 
        // Prompt for the user guess
        // function: printf
        printf("Enter your guess: ");

        // Read user input for user guess
        // function: scanf
        scanf("%d", &playerGuess);
   while (1) {
        // Check if the player's guess is correct
        if (playerGuess == randomNumber) {
            printf("\nCongratulations! You have guessed the random number %d\n", playerGuess);
            break;
        } else if (playerGuess < randomNumber) {
            // Player's guess is too low
            printf("Guessed number is low! Try again.\n");
        } else {
            // Player's guess is too high
            printf("Guessed number is high! Try again.\n");
        }
    }

    // End the program
    // Print a message
    // function: printf
    printf("\nEnd program.");

    // return success;
    return 0;
}

// supporting functions
/*
Name: generateRandomNumber
Process: generates a random number
Function input/parameters: maxNUmber: Maximum number in random number generator
Function output/parameters: None
Function output/returned: randomNum: Generated random number
Dependencies: time.h, stdlib.h - rand, time.
*/
int generateRandomNumber(int maxNumber) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 1 and maxNumber
    int randomNum = (rand() % maxNumber) + 1;

    return randomNum;
}
