//Include necessary header files
#include "matrix_lib.h"  
#include <stdio.h>
#include <stdbool.h>

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

//function multiplyMatrix
bool multiplyMatrix(int aRows, int aCols, int bRows, int bCols, int A[][aCols], int B[][bCols], int prod[aRows][bCols]) {
    // Check if the number of columns in A is equal to the number of rows in B
    if (aCols != bRows) {
        return false; // Multiplication not possible
    }

    // Perform matrix multiplication
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < aCols; k++) {
                // Calculate the dot product of row i of matrix A and column j of matrix B
                prod[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return true; // Multiplication successful
}

//function transposeMatrix
void transposeMatrix(int rows, int cols, int A[][cols], int At[][rows]) {
    // Iterate through each element of the matrix A
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Assign the element at row i and column j of A to row j and column i of At
            At[j][i] = A[i][j];
        }
    }
}