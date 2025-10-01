#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function f(x) = x^3 - x - 2
float f(float x)
{
    return (3*x) - cosf(x) - 1;
    // return (x*x*x) + (2*x) - 2;
}

// Regula Falsi method
float evaluateRegulaFalsi(float a, float b, float error)
{
    float x, prev_x = a;
    while (1)
    {
        // Formula: c = a - f(a) * (b - a) / (f(b) - f(a))
        x = a - (f(a) * (b - a)) / (f(b) - f(a));


        // Check stopping criteria
        if (fabsf(x - prev_x) < error || fabsf(f(x)) < error)
        {
            return x;
        }

        // Update interval
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;

        prev_x = x;
       
    }
}

int main()
{
    float a = 0, b = 0.5; // given initial points
    while(f(a)*f(b)>0){
        a+=0.5;
        b+=0.5;
    }
    printf("a=%f, b=%f\n",a,b);
    int accuracy;

    printf("Enter the number of decimal accuracy digits: ");
    scanf("%d", &accuracy);

    float err = 1;
    for (int i = 0; i < accuracy; i++)
        err /= 10;

    float root = evaluateRegulaFalsi(a, b, err);
    printf("\nApproximate root of x^2 + 2x - 2 = 0 is: %.6f\n", root);

    return 0;
}
