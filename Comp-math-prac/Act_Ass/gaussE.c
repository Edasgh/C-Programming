/*Gauss Elimination Method*/
#include <stdio.h>
#include <math.h>

int main()
{
    int n; // take variable in integer type
    float a[20][20], x[20], m, s = 0.0;
    printf("\nOUTPUT of Gauss Elimination method\n");
    printf("............");
    // printf("\n\nEnter the order (column) and the co-efficient of the matrix\n");
    printf("\n\nEnter the order and the co-efficient of the matrix\n");
    scanf("%d", &n); // the order of matrix
    printf("\nEnter the augmented matrix row-wise....\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            printf("Enter the element in a[%d][%d] : ",i,j);
            scanf("%f", &a[i][j]); // take input of matrix row-wise
        }
    }
    printf("\n\n The entered augmented matrix...\n\n");
    // upper triangular matrix
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            m = a[j][i] / a[i][i]; // for 2nd & 3rd row
            for (int k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - (m * a[i][k]); // mutiply a row by non-zero number & then fill with zeros the lower part of the matrix
            }
        }
    }
    printf("\n\n The upper triangular matrix...\n\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            printf(" %f ", a[i][j]);// print the matrix in which the lower triangle of the principle diagonal entry is zero
        }
        printf("\n");
    }
    x[n] = a[n][n + 1] / a[n][n];
    for (int i = n - 1; i >= 1; i--)
    {
        s = 0.0;
        for (int j = i + 1; j <= n; j++) // calculate the three roots of the equations
        {
            s += a[i][j] * x[j];
        }
        x[i] = (a[i][n + 1] - s) / (a[i][i]);
    }
    printf("\n\nThe required solution\n\n");
    for (int i = 1; i <= n; i++)
    {
        printf("\n\tx%d=%f", i, x[i]); // print the solution
    }

    return 0;
}
