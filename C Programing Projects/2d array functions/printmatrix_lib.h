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

#endif // MATRIX_H
