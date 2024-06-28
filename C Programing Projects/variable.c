// header files
#include <stdio.h>

// Main function
int main() {
    // Declaring variables
    int int_var;
	float float_var;
	double double_var;
	char char_var;
	
	
	// initializing Variable
	int_var = 10;
	float_var = 20.5;
	double_var = 30.75;
	char_var = 'A';
	
	// Delare and initialise variable
	char word[] = "Manissh"; // Corrected line

    // Call the function to display the variables

    printf("Integer variable: %d\n", int_var);
    printf("Float variable: %.2f\n", float_var);
    printf("Double variable: %.2lf\n", double_var);
    printf("Character variable: %c\n", char_var);
    printf("Character variable: %s\n", word);


    // Return success
    return 0;
}