/*
Lab 2 - Problem 2: grade report
Driver: Manish choudhary (mc4323)
Navigator: Anna Cheatham (alc984)
*/


//header file
#include<stdio.h>

//main program
int main()
{
	//Program title
	printf("Grade Report\n");
	printf("============\n\n");
	
	//Initialize Variable
	char name1[10];
	char name2[10];
	double grade1, grade2;
	
	//Ask first student for name
	printf("Type the first student's name: ");
	
	//scan first student name
	scanf("%9s", name1);
	
	//Ask first student for grade
	printf("Type the first student's grade (0-100): ");
	//scan first student grade
	scanf("%lf", &grade1);
	
	//Ask second student for name
	printf("Type the second student's name: ");
	//scan second student name
	scanf("%9s", name2);
	
	//Ask second student for grade
	printf("Type the second student's grade (0-100): ");
	//scan second student grade
	scanf("%lf", &grade2);
	
	//Display student name and grade in table
	
	//print out table title
	printf("\n| %-24s | %-13s |\n", "Student Name", "Student Grade");
	printf("--------------------------------------------\n");
	
	//print out student name with thier grade in the table
	printf("| %-24s | %13.2lf |\n", name1, grade1);
	printf("| %-24s | %13.2lf |\n\n", name2, grade2);

		
	//print out End of program
	printf("End of program\n\n");
	
	//return sucess
	return 0;
}
	