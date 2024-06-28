//header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "hangman_lib.h" 

// Maximum number of unique letters that can be guessed
#define MAX_GUESSED_LETTERS 26  

//main program
int main() {
	// Function to print the welcome message
    printWelcomeMessage(); 
	// Function to initialize random number generator
    initializeRandom(); 
    // Flag to control if the game should be played again
    bool playAgain = true; 
    while (playAgain) {
		// Flag to indicate if the user gives up
        bool giveup; 
		// Function to play the game, returns whether the user won and if they gave up
        bool won = play(&giveup); 
        
        if (giveup) {
            printf("You gave up!\n");
            break; // Exit the game if the user gives up
        } else if (won) {
            printf("You won the round! Well done!\n");
            printf("\nDo you want to play a new round? [y|n]\n");
        } else {
            printf("You lost the round!\n");
            printf("\nDo you want to play a new round? [y|n]\n");
        }

        char response;
        while (1) {
			// Read user's response
            scanf(" %c", &response); 
			// Check if the response is valid
            if (response == 'y' || response == 'n') { 
                break;
            } else {
                printf("I didn't get that. Please use y to yes and n to no.\n");
            }
        }

        if (response == 'n') {
            playAgain = false; // Stop playing if the user doesn't want to play again
        }
    }
	
	//End Message
    printf("Come back another time!\n");
	
	//return success
    return 0;
}
