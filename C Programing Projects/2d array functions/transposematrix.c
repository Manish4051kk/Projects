//header file
#include "matrix_lib.h" 
#include <stdio.h>

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
