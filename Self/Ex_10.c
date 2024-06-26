#include <stdio.h>
// Author : Eshita Das
// gcc Ex_10.c -o Ex_10.exe
//.\Ex_10.exe

// Exercise 10 :  Matrix Multiplication In C
// If there are two matrices or 2-d arrays a[2][2] & b[2][2] then ,( a[0][0]*b[0][0]) + (a[0][1]*b[1][0]) for first element [first row -> first col]
// For second element : first row -> second column (a[0][0]*b[0][1])+(a[0][1]*b[1][1])
// For third element : second row -> first column (a[1][0]*b[0][0])+(a[1][1]*b[1][0])
// For fourth element : second row-> second column (a[1][0]*b[0][1])+(a[1][1]*b[1][1])
// If column no. of a = row no. of b only then we can do multiplication of a and b

void takeVal(int row, int col, int arr[row][col])
{

    if (row > 0 && col > 0)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("Enter value at row = %d , column = %d :", i, j);
                scanf("%d", &arr[i][j]);
                printf("\n");
            }
        }
    }
    else
    {
        printf("Error : Can't add values\n");
    }
}

void printVal(int row, int col, int arr[row][col])
{
    for (int i = 0; i < row; i++)
    {

        printf("|");
        for (int j = 0; j < col; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void multiply(int row1, int row2, int col1, int col2, int arr1[row1][col1], int arr2[row2][col2])
{
    if (col1 == row2)
    {
        int resultArr[row1][col2];
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                // here we can get each element of resultArr
                resultArr[i][j] = 0;
                for (int k = 0; k < row2; k++)
                {
                    resultArr[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }

        printf("Now printing all the values of the multiplication result matrix\n");
        printVal(row1, col2, resultArr);
    }
    else
    {
        printf("The matrices aren't multiplicable\n");
    }
}

void main()
{
    int aRow, aCol, bRow, bCol;

    printf("Matrix multiplication of two matrices : matrixA & matrixB\n");
    printf("Enter the total no. of rows you want in Matrix A :");
    scanf("%d", &aRow);
    printf("\n");

    printf("Enter the total no. of columns you want in Matrix A :");
    scanf("%d", &aCol);
    printf("\n");

    int matrixA[aRow][aCol];
    printf("Now enter all the values you want in Matrix A\n");
    takeVal(aRow, aCol, matrixA);

    printf("Matrix A \n");
    printVal(aRow, aCol, matrixA);

    printf("Enter the total no. of rows you want in Matrix B :");
    scanf("%d", &bRow);
    printf("\n");

    printf("Enter the total no. of columns you want in Matrix B :");
    scanf("%d", &bCol);
    printf("\n");

    int matrixB[bRow][bCol];
    printf("Now enter all the values you want in Matrix B\n");
    takeVal(bRow, bCol, matrixB);

    printf("Matrix B \n");
    printVal(bRow, bCol, matrixB);

    multiply(aRow, aCol, bRow, bCol, matrixA, matrixB);
}