/*
Lab 8 - Problem 2: Array operations - Insertion and Deletion
Driver: Manish choudhary (mc4323)
Navigator: Kevin Martinez (km3589)
*/

//header file
#include <stdio.h>

#define MAX_SIZE 5

// Function prototypes
void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);

//main program
int main() {
    // Print the title of the program
    printf("A program to insert/delete elements in an array:\n");
    printf("===============================================\n");
	
	//initialise and declare variable
    int arr[MAX_SIZE];  // Array to store elements
    int size = 0;        // Current size of the array
    int choice;          // User's choice for insertion or deletion

	printf("Input 1 to insert element and 0 to delete element: ");
    scanf("%d", &choice);

    do {
        if (choice == 1) {
            insertElement(arr, &size);
        } else if (choice == 0) {
            deleteElement(arr, &size);
        } else {
            printf("Invalid choice. Please input 1 for insertion or 0 for deletion.\n");
        }
		// Prompt user for insertion (1) or deletion (0)
        printf("\nInput 1 to insert element and 0 to delete element: ");
        scanf("%d", &choice);
    } while (choice == 1 || choice == 0);

    // End program
    printf("\n\nEnd program.\n");

    return 0;
}

//void insertElement function
void insertElement(int arr[], int *size) {
    if (*size == MAX_SIZE) {
        printf("Error: Array is full. Insertion is not possible.\n");
        return;
    }
	
	//declare variable
    int element, index;

    // Prompt user for element to be inserted
    printf("\nInput the element to be inserted: ");
    scanf("%d", &element);

    // Prompt user for index where element needs to be inserted
    printf("Input the index where the new element needs to be inserted: ");
    scanf("%d", &index);

    while (index < 0 || index > *size) {
        printf("Invalid index. Please try again: ");
		scanf("%d", &index);
    }

    // Shift elements to the right to make space for new element
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new element at the specified index
    arr[index] = element;
    (*size)++;

    // Print the modified array
    printf("\nThe array elements are: ");
    for (int i = 0; i < *size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//void deleteElement function
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("\nError: Array is empty. Deletion is not possible.");
        return;
    }
	
	//declare variable
    int index;

    // Prompt user for index of element to be deleted
    printf("\nInput the index where the element needs to be deleted: ");
    scanf("%d\n\n", &index);

    while (index < 0 || index >= *size) {
        printf("Invalid index. Please try again.\n");
		scanf("%d", &index);
    }

    // Shift elements to the left to fill the gap created by deleted element
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;

    // Print the modified array
    printf("\nThe array elements are: ");
    for (int i = 0; i < *size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

