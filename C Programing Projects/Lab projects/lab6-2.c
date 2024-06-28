/*
Lab 5 - Problem 2: Max & Min
Driver: Manish Choudhary (mc4323)
Navigator: Anna Cheatham (alc984)
*/

// header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant declaration
#define MAXSIZE 100

// prototypes
int generateRandomNumber(int maxNumber);

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
    int max,min;
        // Declaring an array of "size" elements
    int myArray[size];

        // show title
            // function: printf
    printf("A program to find the max and min element in the array\n");
    printf("==================================================\n");

    // Process the data
        // for each index in the array
    for(int i=0;i<size;i++)
    {
        // Populate the array elements
            // function: generateRandomNumber()
        myArray[i] = generateRandomNumber(MAXSIZE);
    }

        // Display array data
            // Prompt for displaying array data
                // function: printf
    printf("The elements in the array are: ");
        // for each index in the array
    for(int i=0;i<size;i++)
    {
        // Display the current element data in array
        printf("%d ",myArray[i]);
    }
    printf("\n");

    // Write code here
	// Step 1: Initialize max and min variables with the first element of the array
	max = myArray[0];
	min = myArray[0];

	// Step 2: Iterate through the array to find max and min elements
	for(int i = 1; i < size; i++) 
	{
    // Check if current element is greater than max
		if(myArray[i] > max) 
		{
			// Update max if current element is greater
			max = myArray[i];
		}
    // Check if current element is smaller than min
		if(myArray[i] < min) 
		{
			// Update min if current element is smaller
			min = myArray[i];
		}
	}


    // Display max and min elements in the array
        // print maximum and minimum elements
            // function: printf
    printf("\nThe maximum element is %d and the minimum element is %d.\n",
           max,min);

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

    // Generate a random number between 1 and maxNumber
        // function: rand()
    int randomNum = (rand() % maxNumber) + 1;
    // Return generated random number
    return randomNum;
}