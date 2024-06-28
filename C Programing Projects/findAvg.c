#include "findAvg.h"

// Function to find the average of elements in an array
double findAvg(double arr[], int size) {
    double sum = 0.0; // Initialize the sum of elements
    // Loop through the array to calculate the sum of elements
    for (int i = 0; i < size; ++i) {
        sum += arr[i]; // Accumulate the sum of elements
    }
    // Calculate and return the average by dividing the sum by the number of elements
    return sum / size;
}
