#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    return (3 * x) - cosf(x) - 1;
}

// h = |f(x1)|*(x2-x1) / |f(x1)|+|f(x2)|
// xn = xn + h

float evaluateRf(float a, float b, float error)
{
    float h, xn;
    int i = 0;
    do
    {
        h = (fabs(f(a)) * (b - a)) / (fabs(f(a)) + fabs(f(b)));
        xn = a + h;
        printf("Iteration %d, a=%12.2f, b=%12.2f, \nh=%12.2f, xn=%f, f(xn)=%12.2f\n", i, a, b, h, xn, f(xn));
        if (f(xn) > 0)
        {
            b = xn;
        }
        else
        {
            a = xn;
        }
        i++;
    } while (fabs(f(xn)) > error);

    return xn;
}
// a b f(a) f(b) h xn f(xn)

void main()
{
    float a = 0, b = 0.5;
    while (1)
    {
        if (f(a) * f(b) < 0)
        {
            printf("Initial values are : a=%f, b=%f\n", a, b);
            break;
        }
        a += 0.5;
        b += 0.5;
    }

    float error;
    printf("Enter the error tolerance : ");
    scanf("%f", &error);
    error = fabs(error);

    float result = evaluateRf(a, b, error);
    printf("Root = %f\n", result);
}
