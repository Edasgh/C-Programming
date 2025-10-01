#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int a)
{
    int f = 1;
    for (int i = 1; i <= a; i++)
    {
        f *= i;
    }
    return f;
}

float evaluateNewtonForward(float x, float table[100][100], float n)
{
    // a+uh = x
    // x = 1.5
    // h = x2-x1
    // a = x1
    // u = x-a/h
    float a, u, h;
    h = table[1][0] - table[0][0];
    a = table[0][0];
    u = (x - a) / h;
    float sum = 0;
    sum += table[0][1];
    float pr=1;
    for (int i = 1; i < n; i++)
    {
        float term = table[0][i+1];
        pr*=(u-(i-1));
        term *= (pr / fact(i));
        sum += term;
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
    // print forward difference table
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            printf("%10.2f ", table[i][j]);
        }
        printf("\n");
    }

    float x ;
    printf("Enter the x value to find f(x) : ");
    scanf("%f",&x);

    float fx=evaluateNewtonForward(x,table,n);
    printf("The result of f(%4.2f) via newton forward method is %f\n",x,fx);
}