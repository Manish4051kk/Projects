/*
Lab 5 - Problem 1: Perfect number checker
Driver: Anna Cheatham (alc984)
Navigator: Manish Choudhary (mc4323)
*/

//Header file
#include <stdio.h>

//main program
int main() {
    // Step 1: Print a title to the program
    printf("A program to calculate the sum of squares of first n even numbers\n");
    printf("===============================================\n");

    // Step 2: Declare necessary variables
    int n, sum = 0;

    // Step 3: Prompt user input and read it.
    printf("Input the value of number n: ");
    scanf("%d", &n);

    // Step 4: Check the validity of the user input
    if (n <= 0) {
        printf("Please enter a positive integer value for n.\n");
    } else {
        // Step 5: If the user input is valid
        printf("\nIteratively calculating the sum of squares of first n even numbers.\n\n");

        // Loop to calculate the sum of squares of even numbers up to n
        for (int i = 1; i <= n; i++) {
            int evenNumber = 2 * i;
            int square = evenNumber * evenNumber;
            sum += square;
            printf("Adding the square of even number %d to the sum of squares variable\n", evenNumber);
            printf("Current value of sum of squares variable is %d.\n\n\n", sum);
        }

        // Print the sum of squares using iterative approach
        printf("The sum of squares of first %d even numbers using iterative approach\n", n);
        printf("is %d.\n\n", sum);

        printf("===============================================\n\n");

        // Step 6: Using formula to calculate the sum of squares
        int sumOfSquares = ((2*n) * (n + 1) * (2 * n + 1)) / 3;

        // Print the sum of squares using the formula
        printf("Using formula to calculate the sum of squares.\n\n");
        printf("The sum of squares of first %d even numbers using formula is %d.\n\n", n, sumOfSquares);
    }

    // End the program with a message to the user
    printf("End of program.\n");

    return 0;
}
