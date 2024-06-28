/*
Lab 5 - Problem 2: Max & Min
Driver: Manish Choudhary (mc4323)
Navigator: Anna Cheatham (alc984)
*/

#include<stdio.h>

// Step 1: Declare a function prototype
void generateFibonacci(int n);

// Step 2: Create the main function
int main() {
    // Print title
    printf("A program to print first n elements in the fibonacci series\n");
    printf("==========================================\n");
    
    // Declare variables
    int n;
    
    // Prompt and read user input
    printf("Input the value of number n: ");
    scanf("%d", &n);
    
    // Check validity of user input
    if (n <= 1) {
        printf("\nInput a positive number greater than 1 for n.\n");
		printf("\nEnd of program.\n");
        return 1; // Exiting program with error code
    }
    
    // Call generateFibonacci function
    generateFibonacci(n);
    
    // End program with a message to the user
    printf("\nEnd of program.\n");
    
    return 0; // Exiting program successfully
}

// Step 3: Implement the generateFibonacci function
void generateFibonacci(int n) {
    int fibonacci[n];
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    printf("\nThe first %d terms in the fibonacci series are: ", n);
    printf("%d %d ", fibonacci[0], fibonacci[1]);
    
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        printf("%d ", fibonacci[i]);
    }
    printf("\n");
}
