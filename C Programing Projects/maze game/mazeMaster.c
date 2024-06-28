/*
Lab 11 - Problem 1: Maze Master
Driver: Manish pratap choudhary (mc4323)
Navigator: Munendra pratap choudhary (mp2893)
*/

// header files
#include "mazeMaster_lib.h"

// main program
int main()
{
    // initialize the program
        // Seed the random number generator
            // functions: srand(), time()
    srand(time(NULL));

        // Declare grid of ROWS rows and COLS cols
            char grid[ROWS][COLS];

        // show title
            // function: printf()
    printf("Welcome to the Maze Master game!");
    printf("================================\n");

        // Initialize grid
            // function: initializeGrid()
    initializeGrid(grid);

        // Print grid
            // function: printGrid()
    printGrid(grid);

    // Write code here for problem 2.
	play(grid);

    // End the program
        // Return success
    return 0;
}
