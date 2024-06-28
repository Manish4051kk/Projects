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

// Function prototypes
int generateRandomNumber(int maxNumber);
void swap(int *a, int *b);
void reverseArray(int arr[], int size);
// Add required function prototypes here

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
    printf("==================================================\n\n");

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
    printf("\n\n");

    // Write code here
        // Reverse the order of array elements
        reverseArray(myArray, size);

    // Display array data
        // Prompt for displaying array data
            // function: printf
    printf("The elements in the array after reversing are ");
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

/*
Name: swap
Process: swaps the values of two integer variables
Function input/parameters: a, b - pointers to integer variables
Function output/parameters: None
Function output/returned: None
Dependencies: None
*/

void swap(int *a, int *b) {
    int temp = *a;  // Store the value pointed to by a in a temporary variable
    *a = *b;        // Assign the value pointed to by b to the memory location pointed to by a
    *b = temp;      // Assign the value stored in temp to the memory location pointed to by b
}

/*
Name: reverseArray
Process: reverses the order of elements in an array
Function input/parameters: arr - array of integers, size - length of the array
Function output/parameters: None
Function output/returned: None
Dependencies: swap function
*/

void reverseArray(int arr[], int size) {
    int start = 0;          // Start index of the array
    int end = size - 1;     // End index of the array

    // Loop until start index is less than end index
    while (start < end) {
        // Swap elements at start and end indices
        swap(&arr[start], &arr[end]);
        // Move towards the center of the array
        start++;
        end--;
    }
}
