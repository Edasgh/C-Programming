#include <stdio.h>
#include <stdlib.h>

float f(float x);

float evaluateSimpsonIntegration(float l, float u, int n);

int main()
{
    float l, u;
    int n;
    printf("Integration using Simpson's Rule:\n");
    // fflush(stdout);

    printf("Enter the no. of intervals: ");
    // fflush(stdout);
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Error: Simpson's rule requires even number of intervals.\n");
        return 0;
    }

    printf("Enter the lower limit: ");
    // fflush(stdout);
    scanf("%f", &l);
    printf("Enter the upper limit: ");
    // fflush(stdout);
    scanf("%f", &u);

    float result = evaluateSimpsonIntegration(l, u, n);
    printf("The result of integration of 4x - 3x^2 from %.2f to %.2f using Simpson's rule with %d intervals is:\n%.4f\n",
           l, u, n, result);

    return 0;
}

float f(float x)
{
    float res = 4 * x - 3 * x * x;
    return res;
}

float evaluateSimpsonIntegration(float l, float u, int n)
{
    float h = (u - l) / n;
    float result = 0;
    int i = 0;
    float x = l;
    while (i <= n)
    {
        if (i == 0 || i == n)
        {
            result += f(x);
        }
        else
        {
            if (i % 2 == 0)
            {
                result += (2 * f(x));
            }
            else
            {
                result += (4 * f(x));
            }
        }

        i++;
        x += h;
    }

    result *= h / 3;
    return result;
}
