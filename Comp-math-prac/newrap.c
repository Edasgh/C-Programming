#include <stdio.h>
#include <math.h>

float f(float x)
{
    // float res = (x * x * x) - (8 * x) - 4;
    float res = (x*x) + (2 * x) - 2;
    return res;
}

float fd(float x)
{
    // float res = (3 * x * x) - 8;
    float res = (2 * x) + 2;
    return res;
}

float findInitialVal()
{
    float a, b;
    float i = 0;
    while (1)
    {
        a = i;
        b = i + 0.5;
        if(f(a)*f(b)<0){
            printf("a=%f , b=%f\n",a,b);
            printf("f(a)=%f, f(b)=%f\n",f(a),f(b));
            if (fabs(f(a)) > fabs(f(b)))
            {
                return b;
            }
            else
            {
                return a;
            }
        }
        i = i + 0.5;
    }
}

float evaluateNewtonRaphson(float x, float error)
{
    while (1)
    {
        float h = (f(x) / fd(x));
        float xn1 = x - h;

        if (fabs(x - xn1) < error)
        {
            return xn1;
        }

        x = xn1;
    }
}

void main()
{
    float a = findInitialVal();
    // a is the found root here
    printf("a=%f\n",a);
    int acc;
    printf("Enter the accuracy upto the decimal point : ");
    scanf("%d", &acc);

    float err = 1;
    for (int i = 0; i < acc; i++)
    {
        err /= 10;
    }

    float root = evaluateNewtonRaphson(a, err);
    printf("The root of x^2 + 2x - 2 = 0 via Newton-Raphson method is : %.2f\n", root);
}