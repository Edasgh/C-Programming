#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    int n;
    printf("Enter the length of data: ");
    scanf("%d", &n);

    float table[n][n + 1];

    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &table[i][0]);
    }

    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("y[%d] = ", i);
        scanf("%f", &table[i][1]);
    }

    // Build difference table
    for (int j = 2; j <= n; j++)
    {
        for (int i = 0; i < n - j + 1; i++)
        {
            table[i][j] = table[i + 1][j - 1] - table[i][j - 1];
        }
    }

    // Print difference table
    printf("\nDifference Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            printf("%10.2f ", table[i][j]);
        }
        printf("\n");
    }

    float val;
    printf("\nEnter the x to find f(x): ");
    scanf("%f", &val);

    float h = table[1][0] - table[0][0];
    float a = table[n - 1][0];
    float u = (val - a) / h;

    float result = table[n - 1][1]; // last y value
    float term = 1.0;

    for (int i = 1; i < n; i++)
    {
        term *= (u + i - 1);
        result += (term / fact(i)) * table[n - i - 1][i + 1];
    }

    printf("\nf(%f) = %f\n", val, result);

    return 0;
}
