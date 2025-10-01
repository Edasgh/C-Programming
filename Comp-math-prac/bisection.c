#include <stdio.h>
#include <math.h>
// take any equation
float f(float x)
{
    float result = 2*x - 3*sinf(x) - 5;
    // x^3 - 9x + 1 = 0
    return result;
}

float evaluateBisection(float *x, float *y, float error)
{
    float a = *x;
    float b = *y;
    while (1)
    {
        float xn1 = (a + b) / 2;

        if (f(xn1) < 0)
        {
            if (fabsf(xn1 - a) < error)
            {
                return a;
            }
            a = xn1;
            *x = xn1;
        }
        else
        {
            if (fabsf(xn1 - b) < error)
            {
                return b;
            }
            b = xn1;
            *y = xn1;
        }
    }
}

void main()
{
    float i = 0;
    float a, b;
    while (1)
    {
        if ((f(i) > 0 && f(i + 1) < 0) || (f(i) < 0 && f(i + 1) > 0))
        {
            a = i;
            b = i + 1;
            break;
        }
        i = i + 1;
    }
    printf("a=%f, b=%f\n",a,b);

    float acc;
    printf("Enter the accuracy upto the decimal places : ");
    scanf("%f", &acc);
    float err = 1;
    for(int i=0;i<acc;i++){
        err/=10;
    }
    float res = evaluateBisection(&a, &b, err);
    printf("The root of the equation : x^3 - 4x - 9 = 0 is , %f \n", res);
}