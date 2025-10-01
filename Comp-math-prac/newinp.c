#include <stdio.h>
#include <math.h>

// factorial
int fact(int x)
{
    int f = 1;
    for (int i = 1; i <= x; i++)
        f *= i;
    return f;
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float table[n][n + 1];

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

    // build forward difference table
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    }

    // print forward difference table
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            printf("%10.2f ", table[i][j]);
        }
        printf("\n");
    }

    float val;
    printf("\nEnter the value of x to find f(x): ");
    scanf("%f", &val);

    float result = 0;

    // decide forward or backward
    if (fabs(val - table[0][0]) <= fabs(val - table[n - 1][0]))
    {
        // -------- Forward Interpolation --------
        float u = (val - table[0][0]) / h;
        result = table[0][1];
        float prod = 1;
        for (int i = 1; i < n; i++)
        {
            prod *= (u - (i - 1)); // u, u(u-1), u(u-1)(u-2), ...
            result += (prod / fact(i)) * table[0][i + 1];
        }
        printf("\nUsing Forward Interpolation:\n");
    }
    else
    {
        // -------- Backward Interpolation --------
        float u = (val - table[n - 1][0]) / h;
        result = table[n - 1][1];
        float prod = 1;
        for (int i = 1; i < n; i++)
        {
            prod *= (u + (i - 1)); // u, u(u+1), u(u+1)(u+2), ...
            result += (prod / fact(i)) * table[n - i - 1][i + 1];
        }
        printf("\nUsing Backward Interpolation:\n");
    }

    printf("f(%.3f) = %.4f\n", val, result);

    return 0;
}
