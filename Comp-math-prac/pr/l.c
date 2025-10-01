#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(int argc, char *argv[])
{
    int n;
    printf("Enter the length of data : ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter the x values : \n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }
    printf("Enter the y values : \n");
    for (int i = 0; i < n; i++)
    {
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    float x1;
    printf("Enter the x to find f(x) : ");
    scanf("%f", &x1);

    float term1 = 1, term2 = 1, result = 0;
    for (int i = 0; i < n; i++)
    {
        term1 = 1, term2 = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                term1 *= (x1 - x[j]);
        }
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                term2 *= (x[i] - x[j]);
            }
        }

        term1 *= y[i];
        result += (term1 / term2);
    }

    printf("f(%f) = %f\n", x1, result);
}