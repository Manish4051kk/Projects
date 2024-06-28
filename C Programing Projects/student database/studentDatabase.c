/*
Lab 12 - Problem 1: Student Database Management System
Driver: Manish Choudhary (mc4323)
Navigator: Munendra choudhary (mp2893)
*/

//header files
#include <stdio.h>
#include "studentDatabase_lib.h"

//main program
int main() {
    // Declare an array of type struct Student and a variable to store the total number of students
    student studentDatabase[MAX_SIZE];
	
	//declare and initialise variable
    int count = 0;
    int choice;
	
	//print welcome message
	printf("\nWelcome to Student Database Management System\n");
	printf("----------------------------------------------------\n");
	
    do {
		// Display welcome message and menu
		printf("\n1. Add student.\n");
		printf("2. Display all student's transcripts.\n");
		printf("3. Exit\n");
		
		//Ask user to input choice
        printf("Input your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(studentDatabase, &count);
                break;
            case 2:
                displayAllStudents(studentDatabase, count);
                break;
            case 3:
                printf("Exiting program!\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
    } while (choice != 3);

	//return success
    return 0;
}
