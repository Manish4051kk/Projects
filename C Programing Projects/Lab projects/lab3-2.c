#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2, num3, num4;

    // Print program title
    printf("Swap the value of two variables\n");
    printf("=========================================\n\n");

    // Prompt user for input
    printf("Input the value of first number: ");
    scanf("%d", &num1);
    printf("Input the value of second number: ");
    scanf("%d", &num2);
	
    // Print values before swapping
    printf("\nThe value of first number is %d and the value of second number is %d before swapping.\n", num1, num2);

    // Swap the values without using a temporary variable
    num3 = num1 + num2;
    num4 = num3 - num2;
    num3 = num3 - num4;

    // Print values after swapping
    printf("The value of first number is %d and the value of second number is %d after swapping.\n", num3, num4);

    // End of program
    printf("\n\nEnd of program\n");

    return 0;
}
