//header file
#include <stdbool.h>
#include "matrix_lib.h" 

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