#include "findMin.h"

// Function to find the minimum element in an array
int findMin(int arr[], int size) {
    int min = arr[0]; // Assume the first element is the minimum
    // Loop through the array starting from the second element
    for (int i = 1; i < size; ++i) {
        // If the current element is smaller than the current minimum, update the minimum
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    // Return the minimum element found
    return min;
}
