/*
Lab 6 - Problem 2: Reverse array elements
Driver: <driver's name> (<driver's student id>)
Navigator: <navigator's name> (navigator's student id)
*/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant declaration
#define MAXSIZE 100

// prototypes
int generateRandomNumber(int maxNumber);
    // Add required function prototype here

// main program
int main()
{
    // initialize the program
        // Seed the random number generator
            // functions: srand(), time()
    srand(time(NULL));

        // Variable declaration
            // functions: generateRandomNumber()
    int size = generateRandomNumber(MAXSIZE);
        // Declaring an array of "size" elements
    int myArray[size];

        // show title
            // function: printf
    printf("A program to reverse the order of elements in an array\n");
    printf("==================================================\n");

    // Process the data
        // for each index in the array
    for(int i = 0; i < size; i++)
    {
        // Populate array elements
            // function: generateRandomNumber()
        myArray[i] = generateRandomNumber(MAXSIZE);
    }

        // Display array data
            // Prompt for displaying array data
                // function: printf
    printf("The elements in the array are ");
        // for each index in the array
    for(int i = 0; i < size; i++)
    {
        // Display the current element data in array
            // function: printf()
        printf("%d ", myArray[i]);
    }
    // Add new line
        // function: printf()
    printf("\n");

        // Write code here







        // Display array data
            // Prompt for displaying array data
                // function: printf
    printf("The elements in the array are ");
        // for each index in the array
    for(int i=0;i<size;i++)
    {
        // Display the current element data in array
            // function: printf()
        printf("%d ", myArray[i]);
    }
    // Add new line
        // function: printf()
    printf("\n");

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

int generateRandomNumber(int maxNumber)
{
    // Generate a random number between 1 and maxNumber
        // function: rand()
    int randomNum = (rand() % maxNumber) + 1;
    // Return generated random number
    return randomNum;
}

// Add function definition here