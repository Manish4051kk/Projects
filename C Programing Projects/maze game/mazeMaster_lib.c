/*
Lab 11 - Problem 1: Maze Master
Driver: Manish pratap choudhary (mc4323)
Navigator: Munendra pratap choudhary (mp2893)
*/

// header file
#include "mazeMaster_lib.h"

/*
Name: generateRandomNumber
Process: generates a random number
Function input/parameters: maxNumber: Maximum number in random number generator
Function output/parameters: None
Function output/returned: randomNum: Generated random number
Dependencies: time.h, stdlib.h - rand, time.
*/
int generateRandomNumber(int maxNumber)
{

    // Generate a random number between 0 and maxNumber
        // function: rand()
    int randomNum = (rand() % maxNumber);

    // Return generated random number
    return randomNum;
}

/*
Name: printGrid
Process: Prints the current state of the grid
Function input/parameters: grid: 2-D array of ROWS rows and COLS columns
Function output/parameters: None
Function output/returned: None
Dependencies: stdio.h - printf .
*/
void printGrid(char grid[ROWS][COLS])
{
    // For each row in the maze
    for (int i = 0; i < ROWS; i++)
    {
        // For each column in the maze
        for (int j = 0; j < COLS; j++)
        {
            // Print the current character in the grid
                // function: printf()
            printf("%c ", grid[i][j]);
        }
        // Print new line
            // function: printf()
        printf("\n");
    }
}

// Write code here

#include "mazeMaster_lib.h"

/*
Name: initializeGrid
Process: Initializes the grid at the start of the game
Function input/parameters: grid: 2-D array of ROWS rows and COLS columns
Function output/parameters: None
Function output/returned: None
Dependencies: generateRandomNumber.
*/
void initializeGrid(char grid[ROWS][COLS])
{
    // Step 1: Iterate through the 2-D array and assign each position with the character 'B' ('B' represents a valid position for movement).
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = VALID_POS;
        }
    }

    // Step 2: Use generateRandomNumber() to generate ROWS number of obstacles in the grid at random positions represented by 'X'.
    for (int i = 0; i < ROWS; i++)
    {
        int obstacleRow = generateRandomNumber(ROWS);
        int obstacleCol = generateRandomNumber(COLS);

        // Ensure that the position is not already an obstacle or the starting/target position
        while (grid[obstacleRow][obstacleCol] != VALID_POS ||
               (obstacleRow == START_ROW && obstacleCol == START_COL) ||
               (obstacleRow == TARGET_ROW && obstacleCol == TARGET_COL))
        {
            obstacleRow = generateRandomNumber(ROWS);
            obstacleCol = generateRandomNumber(COLS);
        }

        grid[obstacleRow][obstacleCol] = OBSTACLE;
    }

    // Step 3: Set the initial position of the user's character at (START_ROW, START_COL) represented by 'C' in the grid.
    grid[START_ROW][START_COL] = CHARACTER_POS;

    // Step 4: Set the target position at (TARGET_ROW, TARGET_COL) represented by 'T' in the grid.
    grid[TARGET_ROW][TARGET_COL] = TARGET_POS;
}



/*
Name: play
Process: Implements the game Maze Master
Function input/parameters: grid: 2-D array of ROWS rows and COLS columns
Function output/parameters: None
Function output/returned: None
Dependencies: stdio.h - printf, printGrid, generateRandomNumber, initializeGrid.
*/
void play(char grid[ROWS][COLS])
{
    // Declare and initialize player and target positions
    int playerRow = 0;
    int playerCol = 0;
    int targetRow = ROWS - 1;
    int targetCol = COLS - 1;

    // Game loop until the player reaches the target
    while (!(playerRow == targetRow && playerCol == targetCol))
    {
        // Print message and get user input for movement
        printf("Enter a move (W/A/S/D or Q to quit): ");
        char move;
        scanf(" %c", &move);

        // Quit if user enters 'Q'
        if (toupper(move) == 'Q')
        {
            printf("You quit the game!\n");
            return;
        }

        // Clear player's current position
        grid[playerRow][playerCol] = VALID_POS;

        // Update player's position based on the move
        switch (toupper(move))
        {
        case 'W':
            if (playerRow > 0 && grid[playerRow - 1][playerCol] != OBSTACLE)
            {
                playerRow--;
            }
			else {
                    printf("Invalid input! Please try again.\n");
                }
            break;
        case 'A':
            if (playerCol > 0 && grid[playerRow][playerCol - 1] != OBSTACLE)
            {
                playerCol--;
            }
			else {
                    printf("Invalid input! Please try again.\n");
                }
            break;
        case 'S':
            if (playerRow < ROWS - 1 && grid[playerRow + 1][playerCol] != OBSTACLE)
            {
                playerRow++;
            }
			else {
                    printf("Invalid input! Please try again.\n");
                }
            break;
        case 'D':
            if (playerCol < COLS - 1 && grid[playerRow][playerCol + 1] != OBSTACLE)
            {
                playerCol++;
            }
			else {
                    printf("Invalid input! Please try again.\n");
                }
            break;
        default:
            printf("Invalid input! Please try again.\n");
            break;
        }

        // Update player's new position
        grid[playerRow][playerCol] = CHARACTER_POS;

        // Print the current state of the grid
        printGrid(grid);
    }

    // Player reached the target
    printf("Congratulations! You won the game.\n");
}
