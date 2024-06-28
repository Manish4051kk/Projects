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

#endif // MATRIX_H