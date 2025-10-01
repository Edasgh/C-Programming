#include <stdio.h>
float f(float x)
{
    return ((4 * x) - (3 * x * x));
}

float evaluateTrapezoidal(float u, float l, int n)
{
    float h = (u - l) / n;
    float x = l;
    float y = 0;
    int i = 0;
    while (i <= n)
    {
        printf("Iteration = %d , x=%f , y=%f \n", i, x, f(x));
        if (i == 0 || i == n)
        {
            y += f(x);
        }
        else
        {
            y += (2 * f(x));
        }
        x += h;
        i++;
    }

    y *= (h / 2);
    return y;
}

void main()
{
    printf("Integrating 4x-3x^2 using Trapezoidal's rule \n ");
    float l, u;
    printf("Enter the lower limit : ");
    scanf("%f", &l);
    printf("Enter the upper limit : ");
    scanf("%f", &u);
    int n;
    printf("Enter the no. of intervals : ");
    scanf("%d", &n);

    float result = evaluateTrapezoidal(u, l, n);
    printf("The result of integrating 4x-3x^2 from lower limit %f to upper limit %f using Trapezoidal rule is :\n%f", l, u, result);
}