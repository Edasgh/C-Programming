#include <stdio.h>
#include <math.h>

int fact(int x)
{
    int n = 1;
    for (int i = 1; i <= x; i++)
    {
        n *= i;
    }
    return n;
}

int main()
{
    float table[100][100];

    int n;
    printf("Enter the length of data: ");
    scanf("%d", &n);

    // input x values
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x(%d) = ", i);
        scanf("%f", &table[i][0]);
    }

    // input y values
    printf("Enter the y values:\n");
    for (int i = 0; i < n; i++)
    {
        printf("y(%d) = ", i);
        scanf("%f", &table[i][1]);
    }

    // check equal spacing
    float h = table[1][0] - table[0][0];
    for (int i = 1; i < n - 1; i++)
    {
        float hi = table[i + 1][0] - table[i][0];
        if (fabs(hi - h) > 1e-6)
        {
            printf("Error: x values are not equally spaced. Newton interpolation not valid.\n");
            return 0;
        }
    }

    // build difference table
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    }

    // print difference table
    printf("\n Difference Table:\n");
    printf("%12s %12s", "x", "y");
    for (int i = 2; i <= n; i++)
    {
        printf("%12s%d", "del^", i - 1);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            printf("%12.2f ", table[i][j]);
        }
        printf("\n");
    }

    float val;
    printf("\nEnter the value of x to find f(x): ");
    scanf("%f", &val);

    // -------- Backward Interpolation --------
    float u = (val - table[n - 1][0]) / h;
    float result = table[n - 1][1];
    float prod = 1;
    for (int i = 1; i < n; i++)
    {
        prod *= (u + (i - 1)); // u, u(u+1), u(u+1)(u+2), ...
        float term = (prod / fact(i)) * table[n - i - 1][i + 1];
        result += term;
        if (i == n - 1)
        {
            printf("%f = %f\n", term,result);
        }
        else
        {
            printf("%f + ", term);
        }
    }

    printf("f(%.3f) = %.4f\n", val, result);
    return 0;
}