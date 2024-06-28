/*
Lab 1 - Problem 1: Hello World with date of birth and age
Driver: Anna Cheatham (alc984)
Navigator: Manish Choudhary (mc4323)
*/

// header files
#include <stdio.h>

// main program
int main()
{
    // initialize program
		// declare variables
	char name[10];
	int age;
	char dob[6];
	
	    // show title
	printf("A program to say your name, age and date of birth!\n");
	printf("==================================================\n\n");
	
	// get user input
		// prompt the user for name
	printf("Type your name: ");
	
		// read name from user input
	scanf("%9s", name);	
	
		// prompt the user for age
	printf("Type your age: ");
	
		// read age from user input
	scanf("%d", &age);
	
		// prompt the user for date of birth
	printf("Type your date of birth (mm-dd): ");
	
		// read date of birth from user input
	scanf("%5s", dob);
	
	// show message
		//print out message
	printf("\nHi %s! You have %d years old and ", name, age); 
	printf("your birthday is on %s. Happy Birthday!\n\n", dob);
	
	// end program
		// print out a message
	printf("End of program\n\n");
	
		//return success
	return 0;
}