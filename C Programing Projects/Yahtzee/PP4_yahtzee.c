// header files
#include "yahtzee_lib.h"

// main program
int main()
{
    // initialize program
    // initialize the random number generator
    initializePlayer();
    // declare variable to hold the dice
    int dice[NUM_DICE];

    // declare the variable to store the user's choice
    char choice;
    // inialize the variable that stores the play
    int play = NO_PLAY;

    // print a title
    printf("Welcome to Simple Yahtzees!\n");
    printf("==========================\n\n");

    // begin game
    // prompt the user for the play
    printf("Do you want to roll the dice (y/n): ");
    // wait for user input
    choice = getChoice();

    // create a loop that runs while the user wants to continue
    while (choice == 'y') {
        // roll the dice to fill the array of dice
        for (int i = 0; i < NUM_DICE; i++) {
            dice[i] = rollDice();
        }

        // print the dice
        printf("You roll: ");
        for (int i = 0; i < NUM_DICE; i++) {
            printf("%d", dice[i]);
            if (i != NUM_DICE - 1) {
                printf(", ");
            }
        }
        printf("\n");

        // call the function decidePlay and store the result in the play variable
        play = decidePlay(dice);

        // evaluate the play variable and print the appropriate message
        switch (play) {
            case YAHTZEE:
                printf("You rolled a Yahtzee!\n");
                break;
            case FOUR_OF_A_KIND:
                printf("You rolled a Four of a Kind!\n");
                break;
            case THREE_OF_A_KIND:
                printf("You rolled a Three of a Kind!\n");
                break;
            case FULL_HOUSE:
                printf("You rolled a Full House!\n");
                break;
            case L_STRAIGHT:
                printf("You rolled a Large Straight!\n");
                break;
            case S_STRAIGHT:
                printf("You rolled a Small Straight!\n");
                break;
            case NO_PLAY:
                printf("You rolled no particular play!\n");
                break;
            default:
                printf("Invalid play.\n");
                break;
        }

        // prompt the user for continuing
        printf("Play again? (y/n): ");
        // Read the choice
        choice = getChoice();
    } // END OF loop

    // End program
    // print a message
    printf("Thanks for playing Yahtzee!\n");
    // return success
    return 0;
}
