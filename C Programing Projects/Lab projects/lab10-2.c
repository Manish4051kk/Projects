/*
Lab 10 - Problem 2: Separate vowels
Driver: Manish Choudhary (mc4323)
Navigator: Tyson Charles (tjc558)
*/

//header file
#include <stdio.h>

//main program
int main() {
    // Print title
    printf("Separate Vowels from File\n");
    printf("==========================\n\n");

    // Declare variables
    char ch;
    char fileName[100];

    // Prompt user for input file name
    printf("Input file name to separate vowels: ");
    scanf("%s", fileName);

    // Open files
    FILE *inputFile = fopen(fileName, "r");
    FILE *consonantsFile = fopen("consonants.txt", "w");

    // Check if files are opened successfully
    if (inputFile == NULL || consonantsFile == NULL) {
		//error message
        printf("Error in opening the files.\n");
        return 1; // Exit program with error
    }

    // Read characters from input file and write consonants to consonantsFile
    while ((ch = fgetc(inputFile)) != EOF) {
        // Check if current character is not a vowel
        if (ch != 'A' && ch != 'a' &&
            ch != 'E' && ch != 'e' &&
            ch != 'I' && ch != 'i' &&
            ch != 'O' && ch != 'o' &&
            ch != 'U' && ch != 'u') {
            // Write consonant to consonantsFile
            fputc(ch, consonantsFile);
        }
    }

    // Close files
    fclose(inputFile);
    fclose(consonantsFile);

    // Closing message
    printf("Consonants separated successfully.\n");
		
	// End program
	printf("\nEnd program\n");

	// return success
    return 0;
}
