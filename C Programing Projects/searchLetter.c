#include "searchLetter.h"

// Function to search for a letter in an array of characters
int searchLetter(char arr[], int size, char letter) {
    // Loop through the array to search for the letter
    for (int i = 0; i < size; ++i) {
        // If the current element matches the letter, return its position (index)
        if (arr[i] == letter) {
            return i;
        }
    }
    // If the letter is not found in the array, return -1
    return -1;
}
