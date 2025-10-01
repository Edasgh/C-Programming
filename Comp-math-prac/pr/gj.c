#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a[10][10], b[10], x[10], xn[10], sum, e;
    int i, j, n, flag = 0, key, iter = 1;
    printf("\nThis program illustrates Gauss-Jacobi method to solve system AX = B\n");
    printf("\nEnter the dimensions of coefficient matrix n (n<=10): "); // Input size
    scanf("%d", &n);
    printf("\nEnter the elements of (co-efficient matrix) matrix A (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("\nEnter the elements of (value matrix) matrix B (%d elements):\n", n); // Input RHS vector B
    for (i = 0; i < n; i++)
    {
        printf("b[%d] = ", i);
        scanf("%f", &b[i]);
    }
    printf("\nThe system of linear equations:\n"); // Display system
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("(%.2f)x%d", a[i][j], j + 1);
            if (j < n - 1)
                printf(" + ");
        }
        printf(" = (%.2f)\n", b[i]);
    }
    for (i = 0; i < n; i++) // Check diagonal dominance
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            sum += fabs(a[i][j]);
        }
        sum -= fabs(a[i][i]);
        if (fabs(a[i][i]) < sum)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\nThe system is NOT diagonally dominant, Jacobi may not converge.\n");
        return 0;
    }
    else
    {
        printf("\nThe system IS diagonally dominant (good for Jacobi).\n");
        printf("\nEnter the initial approximations:\n"); // Initial guess
        for (i = 0; i < n; i++)
        {
            printf("x[%d] = ", i + 1);
            scanf("%f", &x[i]);
        }
        printf("\nEnter the error tolerance: "); // Error tolerance
        scanf("%f", &e);
    }
    printf("\nIteration results:\n"); // Iterations
    for (i = 0; i < n; i++)
    {
        printf("   x[%d]\t", i + 1);
    }
    printf("\n");
    key = 0;
    while (1)
    {
        key = 0;
        for (i = 0; i < n; i++)
        {
            sum = b[i];
            for (j = 0; j < n; j++)
            {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            xn[i] = sum / a[i][i];
            if (fabs(xn[i] - x[i]) < e)
            {
                key++;
            }
        }
        printf("%3d:", iter++); // Print iteration values
        for (i = 0; i < n; i++)
        {
            printf(" %10.6f ", xn[i]);
            x[i] = xn[i];
        }
        printf("\n");
        if (key == n) // Check convergence
            break;
    }
    printf("\nAn approximate solution is:\n"); // Final solution
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %.6f\n", i + 1, x[i]);
    }
    return 0;
}
