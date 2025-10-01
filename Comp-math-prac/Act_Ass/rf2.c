#include <stdio.h>
#include <math.h>

float f(float);

int main()
{
    float x1, x2, xn, h, accuracy;
    int k = 1;

    do
    {
        printf("Enter the initial guess for x1: ");
        scanf("%f", &x1);

        printf("Enter the initial guess for x2: ");
        scanf("%f", &x2);

        if (f(x1) * f(x2) > 0)
            printf("Root is not covered with the initial guess..\n");

    } while (f(x1) * f(x2) > 0);

    printf("Enter the accuracy: ");
    scanf("%f", &accuracy);
    accuracy = fabs(accuracy);

    do
    {
        printf("Iteration: %d\n", k++);
        printf("x1 = %f, x2 = %f\n", x1, x2);
        printf("f(x1) = %f, f(x2) = %f\n", f(x1), f(x2));

        h = (fabs(f(x1)) * (x2 - x1)) / (fabs(f(x1)) + fabs(f(x2)));
        xn = x1 + h;

        printf("h = %f, f(xn) = %f\n", h, f(xn));

        if (f(xn) < 0)
            x1 = xn;
        else
            x2 = xn;

    } while (fabs(f(xn)) > accuracy);

    printf("Root = %f\n", xn);
    return 0;
}

float f(float x)
{
    float x_val;
    x_val = 3 * x - cosf(x) - 1;
    return x_val;
}