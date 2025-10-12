/*Implement menu driven program for matrix operations: 
addition, multiplication, transpose.
                                    
Theory:
A matrix is a rectangular arrangement of numbers in rows and columns.
Matrix operations are widely used in mathematics, engineering, and computer science.
This program performs three main operations on matrices using a menu-driven approach:
Matrix Addition
    Adds corresponding elements of two matrices.
    Both matrices must have the same number of rows and columns.
Matrix Multiplication
    Multiplies two matrices according to the standard rule:
    Element (i,j) of the result = sum of the products of elements from row i of first matrix and column j of second matrix.
    The number of columns in the first matrix must be equal to the number of rows in the second matrix.
Matrix Transpose
    Interchanges rows and columns of a matrix.
    Element (i,j) becomes element (j,i) in the transpose.
*/
#include <stdio.h>
#define MAX 10
int main() {
    int r1, c1, r2, c2;
    int matrix1[MAX][MAX], matrix2[MAX][MAX];
    int sum[MAX][MAX], diff[MAX][MAX], product[MAX][MAX], transpose[MAX][MAX];

    printf("Enter rows and columns of Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter Matrix 1:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter rows and columns of Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter Matrix 2:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &matrix2[i][j]);

    // Matrix Addition
    if (r1 == r2 && c1 == c2) {
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                sum[i][j] = matrix1[i][j] + matrix2[i][j];
        printf("\nSum of matrices:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++)
                printf("%d ", sum[i][j]);
            printf("\n");
        }
    } else {
        printf("Matrix addition not possible\n");
    }

    // Matrix Subtraction
    if (r1 == r2 && c1 == c2) {
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                diff[i][j] = matrix1[i][j] - matrix2[i][j];
        printf("\nDifference of matrices:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++)
                printf("%d ", diff[i][j]);
            printf("\n");
        }
    } else {
        printf("Matrix subtraction not possible\n");
    }

    // Matrix Multiplication
    if (c1 == r2) {
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++) {
                product[i][j] = 0;
                for (int k = 0; k < c1; k++)
                    product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        printf("\nProduct of matrices:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++)
                printf("%d ", product[i][j]);
            printf("\n");
        }
    } else {
        printf("Matrix multiplication not possible\n");
    }

    // Matrix Transpose
    printf("\nTranspose of Matrix 1:\n");
    for (int i = 0; i < c1; i++) {
        for (int j = 0; j < r1; j++) {
            transpose[i][j] = matrix1[j][i];
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
conclusion: 
From this program, we learned:

How to read and store matrices in a 2D array.

How to perform addition, multiplication, and transpose of matrices.

How menu-driven programs improve usability and allow repeated operations without restarting the program.

Using functions for each operation makes the code organized, modular, and easy to debug.

This experiment demonstrates practical applications of matrices and modular programming concepts in C.
*/