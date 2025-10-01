#include <stdio.h> // Header files
#include <math.h>  // Header files

float f(float x) // Function of x, i.e – f(x).
{
    return  (x * x) + (2 * x) - 2;
}

float df(float x) // Derivative of f(x), i.e – f’(x).
{
    return (2 * x) + 2;
}

int main()
{
    int k = 1; // variable declaration
    float x1, x2, xn, h, acc;

    do // Do while loop starts here
    {
        printf("Enter initial guess for x1: ");
        scanf("%f", &x1);
        printf("Enter initial guess for x2: ");
        scanf("%f", &x2);

        // Check convergence condition
        if (f(x1) * f(x2) > 0)
            printf("No convergence for root...\n");

    } while (f(x1) * f(x2) > 0); // Do while loop ends here

    printf("Enter desired accuracy: ");
    scanf("%f", &acc); // Take the value of acc.
    acc = fabs(acc);
    xn = x1;

    do // Do while loop starts here
    {
        printf("Iteration: %d\n", k++);
        printf("xn = %f ; f(xn) = %f ; df(xn) = %f\n", xn, f(xn), df(xn));
        h = -(f(xn) / df(xn));
        xn = xn + h;
        printf("h = %f ; xn+1 = %f\n", h, xn);
        printf("---------------------------\n");

    } while (fabs(h) > acc); // Do while loop ends here

    printf("Root = %f\n", xn); // Print xn
    return 0;
}

