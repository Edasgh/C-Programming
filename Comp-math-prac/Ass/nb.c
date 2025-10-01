#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fact(int a)
{
    int f = 1;
    for (int i = 1; i <= a; i++)
    {
        f *= i;
    }
    return f;
}

float evaluateNewtonBackward(float x, float table[100][100], int n)
{
    // x = 7.5
    float a, u, h;
    h = table[n - 1][0] - table[n - 2][0];
    a = table[n - 1][0];
    u = (x - a) / h;
    float sum = 0;
    float pr = 1;
    sum += table[n - 1][1];
    for (int i = 1; i < n; i++)
    {
        pr *= (u + (i - 1));
        sum += (pr / fact(i)) * table[n - i - 1][i + 1];
    }
    return sum;
}

void main()
{
    float table[100][100];
    int n;
    printf("Enter the size of data : ");
    scanf("%d", &n);

    printf("Enter the x values : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter x(%d) : ", i);
        scanf("%f", &table[i][0]);
    }
    printf("Enter the y values : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter y(%d) : ", i);
        scanf("%f", &table[i][1]);
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    }

    printf("Printing the difference table : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            printf("%10.2f ", table[i][j]);
        }
        printf("\n");
    }

    float x;
    printf("Enter the x value to find f(x) : ");
    scanf("%f", &x);

    float fx = evaluateNewtonBackward(x, table, n);
    printf("The result of f(%4.2f) via newton backward method is %f\n", x, fx);
}