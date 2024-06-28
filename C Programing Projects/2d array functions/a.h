#ifndef MATRIX_H
#define MATRIX_H

/**
 * Name: printMatrix
 * Process: Prints out a 2D array in a tabular format
 * Function input/parameters:
 *     rows - number of rows in the matrix
 *     cols - number of columns in the matrix
 *     A - 2D array representing the matrix
 *     digits - maximum number of digits for alignment
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: None
 **/
#include <stdbool.h>

void printMatrix(int rows, int cols, int A[][cols], int digits);

/**
 * Name: multiplyMatrix
 * Process: Calculates the product of two matrices A and B
 * Function input/parameters:
 *     aRows - number of rows in matrix A
 *     aCols - number of columns in matrix A
 *     bRows - number of rows in matrix B
 *     bCols - number of columns in matrix B
 *     A - 2D array representing matrix A
 *     B - 2D array representing matrix B
 *     prod - 2D array to store the product of A and B
 * Function output/parameters: None
 * Function output/returned: Returns true if multiplication is possible, false otherwise
 * Dependencies: None
 **/
bool multiplyMatrix(int aRows, int aCols, int bRows, int bCols, int A[][aCols], int B[][bCols], int prod[aRows][bCols]);

/**
 * Name: transposeMatrix
 * Process: Produces the transpose of a given matrix A
 * Function input/parameters:
 *     rows - number of rows in the matrix
 *     cols - number of columns in the matrix
 *     A - 2D array representing the matrix
 *     At - 2D array to store the transpose of A
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: None
 **/
void transposeMatrix(int rows, int cols, int A[][cols], int At[][rows]);

#endif // MATRIX_H
