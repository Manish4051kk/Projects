/*
Lab 5 - Problem 1: Perfect number checker
Driver: Manish Choudhary (mc4323)
Navigator: Anna Cheatham (alc984)
*/

//Header file
#include <stdio.h>

// main program
int main() {
    // Step 1: Print a title message
    printf("A program to check if a number n is a perfect number\n");
    printf("======================================\n");

    // Step 2: Declare necessary variables
    int num;
    
    // Step 3: Prompt user to get input and read it
	printf("Input the value of number n: ");
    scanf("%d", &num);
    
    /// Step 4: Check validity of user input
    if (num <= 1) 
	{
		//print Perfect numbers are defined only for positive integers
        printf("\nPerfect numbers are defined only for positive integers greater than 1\n\n");
    } 
    // Step 5: Calculate the sum of all factors of the number
    else 
	{
        int sum = 0;
        for (int i = 1; i <= num / 2; i++) 
		{
            if (num % i == 0) 
			{
                sum += i;
            }
        }
        if (sum == num) 
		{
            printf("\n%d is a perfect number.\n\n", num);
        } else 
		{
            printf("\n%d is not a perfect number.\n\n", num);
        }
    }
	
	// Step 7: End the program with a message to the user
    printf("End of program\n");

	//return success
    return 0;
}



