/*
Lab 4 - Problem 1: Factorial calculator
Driver: Manish Choudhary (mc4323)
Navigator: Eric Derr (ejd269)
*/

//header file
#include <stdio.h>

//main program
int main() {
	//initialize and declare variables
    int num, factorial = 1;
	
	//Print out  title message
	printf("A program to calculate the factorial of a number n\n");
	printf("===================================\n\n");

	// prompt user to enter the value of number
    printf("Input the value of the number n: \n\n");
	
	//use scanf to read the value of number
    scanf("%d", &num);

    // Check if the number is negative
    if (num < 0) 
	{
		//print factorial is not defined
        printf("Factorial is not defined for negative numbers.\n\n");
    }
	//check if the number is zero
	else if(num = 0){
		//print out factorial of 0 is 1
		printf("The factorial of the number 0 is 1\n\n");
	}
	//else find factorial using for loop 
	else {
		//use for loop to find factorial
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
		//print out factorial of the number is
        printf("The factorial of the number %d is %d.\n\n", num, factorial);
    }


	//End message
	printf("End of program\n");
	
	//return success
    return 0;
}
