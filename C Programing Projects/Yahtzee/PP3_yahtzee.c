// header files
#include "yahtzee_lib.h"

// main program
int main()
{
    // initialize program
        // initialize the random number generator
            // function: initializePlayer
    initializePlayer();
        // declare variables to hold the dice
    int dice1, dice2, dice3, dice4, dice5;

        // declare the variable to store the user's choice
    char choice;
        // inialize the variable that stores the play
    int play = NO_PLAY;

        // print a title
    printf("\nWelcome to Simple Yahtzee!\n");
    printf("==========================\n\n");

    // begin game
        // prompt the user for the play
            // function: printf
    printf("Do you want to roll the dice (y/n): ");
        // wait for user input
            // function: getChoice
    scanf(" %c", &choice);
    choice = tolower(choice);
    while (choice != 'y' && choice != 'n') {
        printf("Invalid option. Please type 'y' to play or 'n' to exit: ");
        scanf(" %c", &choice);
        choice = tolower(choice);
    }

        // create a loop that runs while the user wants to continue
    while (choice == 'y') {
        // roll the dice (one at a time)
        dice1 = rollDice();
        dice2 = rollDice();
        dice3 = rollDice();
        dice4 = rollDice();
        dice5 = rollDice();

        // print the dice
        printf("Your roll: %d, %d, %d, %d, %d\n", dice1, dice2, dice3, dice4, dice5);

        // call the function decidePlay and store the result in the play variable
        play = decidePlay(dice1, dice2, dice3, dice4, dice5);

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
        printf("\nPlay again? (y/n): ");
        // Read the choice
        scanf(" %c", &choice);
        choice = tolower(choice);
        while (choice != 'y' && choice != 'n') {
            printf("Invalid option. Please type 'y' to play or 'n' to exit: ");
            scanf(" %c", &choice);
            choice = tolower(choice);
        }
    }

    // print a message
    printf("\nThanks for playing Yahtzee!\n");
    // return success
    return 0;
}
