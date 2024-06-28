/*
Lab 13 - Problem 1: Linked List
Driver: Manish Choudhary (mc4323)
Navigator: Munendra Choudhary (mp2893)
*/

//header files
#include <stdio.h>  
#include <stdlib.h>  

// Global constant for the maximum size of the array
#define MAX_SIZE 10  

// Structure for a linked list node
struct node {
	// Data stored in the node
    int data;  
	// Pointer to the next node
    struct node* next;  
};

// Function prototype for creating a linked list from an array
struct node* createLinkedList(int* myArray);

// Function prototype for displaying the contents of a linked list
void displayContents(struct node* head);

//main program
int main() {
	// Program title
    printf("A program to construct a linked list.\n");  
    printf("====================\n"); 
	
	//initialise and declare variable
		// Array of integers with size MAX_SIZE
    int myArray[MAX_SIZE];  
		// Pointer to the first node in the linked list
    struct node* head = NULL;  

    // Populate the array with index values
    for (int i = 0; i < MAX_SIZE; i++) {
		// Assign index value to each array element
        myArray[i] = i;  
    }

	// Create the linked list from the array
    head = createLinkedList(myArray);  

	// Message before displaying the list
    printf("The contents of the linked list are: ");  
	// Display the linked list contents
    displayContents(head);  

    // Free the memory allocated to the linked list nodes
		// Pointer to iterate over the list
    struct node* current = head;  
		// Temporary pointer to hold the next node
    struct node* nextNode;  
	
	// Iterate until the end of the list
    while (current != NULL) {  
		// Store the next node
        nextNode = current->next;  
		// Deallocate the current node
        free(current);  
		// Move to the next node
        current = nextNode;  
    }
	
	// Message indicating the end of the program
    printf("End of program.\n");  

	//return success
    return 0;  
}

// Function to create a linked list from an array
struct node* createLinkedList(int* myArray) {
	// Head pointer for the linked list
    struct node* head = NULL;  
	// Tail pointer for the linked list
    struct node* tail = NULL;  

    // Iterate over the array to create linked list nodes
    for (int i = 0; i < MAX_SIZE; i++) {
		// Allocate memory for a new node
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
		// Set the node data from the array			
        newNode->data = myArray[i];  
		// Initialize the next pointer to NULL
        newNode->next = NULL;  

		// If this is the first node
        if (head == NULL) {  
			// Set both head and tail to the new node
            head = tail = newNode;  
        }
		// If not the first node
		else {  
			// Link the current tail to the new node
            tail->next = newNode;  
			 // Update the tail pointer to the new node
            tail = newNode; 
        }
    }

	// Return the head pointer of the linked list
    return head;  
}

// Function to display the contents of a linked list
void displayContents(struct node* head) {
	// Temporary pointer to traverse the list
    struct node* temp = head;  

	// Loop until the end of the list
    while (temp != NULL) {  
		// Print the data of the current node
        printf("%d ", temp->data);  
		// Move to the next node
        temp = temp->next;  
    }

    printf("\n"); 
}
