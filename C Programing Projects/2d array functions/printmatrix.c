//header file
#include <stdio.h>
#include "matrix_lib.h" 

//function printMatrix
void printMatrix(int rows, int cols, int A[][cols], int digits) {
    // Loop through each row
    for (int i = 0; i < rows; i++) {
        // Loop through each column
        for (int j = 0; j < cols; j++) {
            // Print the element with appropriate spacing
            printf("%*d", digits, A[i][j]);
            
            // If it's not the last column, print a space
            if (j < cols - 1) {
                printf(" ");
            }
        }
        // Move to the next line after each row
        printf("\n");
    }
}
