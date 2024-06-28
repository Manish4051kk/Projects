/*
Lab 5 - Problem 2: Max & Min
Driver: Manish Choudhary (mc4323)
Navigator: Anna Cheatham (alc984)
*/


//header file
#include <stdio.h>

// Function prototype for swapping two integers using pointers
void swap(int *a, int *b);

//main program
int main() {
    // Print program title
    printf("Swap the values of two variables\n");
    printf("==============================================\n\n");

    // Declare variables
    int num1, num2;

	// Prompt user to input value for number 1
	printf("Input the value of first number: ");
		// scan the user input  
    scanf("%d", &num1);
		
	// Prompt user to input value for number 2
    printf("Input the value of second number: ");
		// scan the user input
	scanf("%d", &num2);

    // Print values before swapping
    printf("\nThe value of first number is %d and the value of second number is %d before swapping.\n", num1, num2);

    // Swap the values using the swap function
    swap(&num1, &num2);

    // Print values after swapping
    printf("The value of first number is %d and the value of second number is %d after swapping.\n", num1, num2);

    // End of program
    printf("\nEnd of program\n");

    return 0;
}

// Function definition to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;  // Store the value pointed to by a in a temporary variable
    *a = *b;        // Assign the value pointed to by b to the memory location pointed to by a
    *b = temp;      // Assign the value stored in temp to the memory location pointed to by b
}
