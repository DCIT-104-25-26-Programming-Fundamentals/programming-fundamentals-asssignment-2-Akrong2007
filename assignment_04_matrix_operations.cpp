// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rowsA, colsA;
    printf("Enter number of rows: ");
    scanf("%d", &rowsA);
    printf("Enter number of columns: ");
    scanf("%d", &colsA);

    if (rowsA < 1 || rowsA > MAX_SIZE || colsA < 1 || colsA > MAX_SIZE) {
        printf("Error: Matrix dimensions must be between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    printf("\nEnter Matrix A:\n");
    readMatrix(matrixA, rowsA, colsA);

    printf("\nOriginal Matrix:\n");
    printMatrix(matrixA, rowsA, colsA);

    int transposed[MAX_SIZE][MAX_SIZE];
    transposeMatrix(matrixA, rowsA, colsA, transposed);
    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, colsA, rowsA);

    int matrixB[MAX_SIZE][MAX_SIZE];
    printf("\nEnter Matrix B (same size as A):\n");
    readMatrix(matrixB, rowsA, colsA);

    int sumResult[MAX_SIZE][MAX_SIZE];
    addMatrices(matrixA, matrixB, rowsA, colsA, sumResult);
    printf("\nSum of Matrix A and B:\n");
    printMatrix(sumResult, rowsA, colsA);

    int rowsC, colsC;
    printf("\nEnter number of rows for Matrix C: ");
    scanf("%d", &rowsC);
    printf("Enter number of columns for Matrix C: ");
    scanf("%d", &colsC);

    if (rowsC < 1 || rowsC > MAX_SIZE || colsC < 1 || colsC > MAX_SIZE) {
        printf("Error: Matrix dimensions must be between 1 and %d.\n", MAX_SIZE);
        return 0;
    }

    if (rowsC != colsA) {
        printf("Error: Number of columns in A must equal number of rows in C.\n");
        return 0;
    }

    int matrixC[MAX_SIZE][MAX_SIZE];
    printf("\nEnter Matrix C:\n");
    readMatrix(matrixC, rowsC, colsC);

    int productResult[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixA, matrixC, rowsA, colsA, colsC, productResult);
    printf("\nProduct of Matrix A and C:\n");
    printMatrix(productResult, rowsA, colsC);

    return 0;
}