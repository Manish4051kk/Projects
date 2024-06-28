#include <stdio.h>
#include <string.h>
#include <ctype.h> 

// Function prototype for encrypt function
void encrypt(char *message, int shift);

int main() {
    // Print title of the program
    printf("Program to encrypt message using Caesar cipher:\n");
    printf("================================================\n");

    // Declare necessary variables
    char message[100];
    int shift;

    // Prompt the user to input message and shift
    printf("Input a message to encrypt:");
    fgets(message, sizeof(message), stdin);
    printf("\nInput the value of shift for Caesar cipher: ");
    scanf("%d", &shift);

    // Call the encrypt function with message and shift
    encrypt(message, shift);

    // Print the encrypted message
    printf("\nEncrypted message is: %s", message);

    // End the program with a closing message
    printf("\nEnd program.\n");

    return 0;
}

// Function definition for encrypt function
void encrypt(char *message, int shift) {
    int size = strlen(message);
    int i;

    // Iterate through each character of the message
    for (i = 0; i < size; i++) {
        // Check if the character is an alphabet
        if (isalpha(message[i])) {
            // Convert lowercase to uppercase
            if (islower(message[i])) {
                message[i] = toupper(message[i]);
            }
            // Encrypt the character by shifting
            message[i] = ((message[i] - 'A' + shift) % 26) + 'A';
        }
    }
}
