/*
Lab 5 - Problem 1: Perfect number checker
Driver: <driver's name> (<driver's student id>)
Navigator: <navigator's name> (<navigator's student id>)
*/

//Header file
#include <stdio.h>

// Function to check if the number is perfect
int isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

// main program
int main() {
    // Step 1: Print a title message
    printf("A program to check if a number n is a perfect number\n");
    printf("======================================\n");

    // Step 2: Declare necessary variables
    int num;

    // Step 3: Prompt foto get user input and read it
    printf("Input the value of number n: ");
    scanf("%d", &num);

    // Step 4: Check validity of user input
    if (num <= 1) {
		
        printf("\nPerfect numbers are defined only for positive integers greater than 1\n\n");
    } else {
        // Step 5: Calculate the sum of all factors of the number
        if (isPerfect(num)) {
            // Step 6: Check if the sum equals the user's initial input and print a message
            printf("\n%d is a perfect number.\n\n", num);
        } else {
            printf("\n%d is not a perfect number.\n\n", num);
        }
    }

    // Step 7: End the program with a message to the user
    printf("End of program\n");

	//return success
    return 0;
}
