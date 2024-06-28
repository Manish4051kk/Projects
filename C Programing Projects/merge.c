#include "merge.h"

// Function to merge two sorted arrays into a single sorted array
void merge(int arr1[], int arr2[], int mergedArr[]) {
    int i = 0, j = 0, k = 0; // Initialize indices for arr1, arr2, and mergedArr respectively

    // Loop until either arr1 or arr2 is fully traversed
    while (i < 5 && j < 5) {
        // Compare elements of arr1 and arr2, and insert the smaller element into mergedArr
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++]; // Insert element of arr1 into mergedArr
        } else {
            mergedArr[k++] = arr2[j++]; // Insert element of arr2 into mergedArr
        }
    }

    // If there are remaining elements in arr1, append them to mergedArr
    while (i < 5) {
        mergedArr[k++] = arr1[i++];
    }

    // If there are remaining elements in arr2, append them to mergedArr
    while (j < 5) {
        mergedArr[k++] = arr2[j++];
    }
}
