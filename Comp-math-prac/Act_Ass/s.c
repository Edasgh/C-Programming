#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - x - 1; // Example: f(x) = x^3 - x - 1
}

int main()
{
    double x0, x1, x2, f0, f1, f2, e;
    int step = 1, N;

    // Input section
    printf("Enter first guess: ");
    scanf("%lf", &x0);
    printf("Enter second guess: ");
    scanf("%lf", &x1);
    printf("Enter tolerable error: ");
    scanf("%lf", &e);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &N);

    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");

    do
    {
        f0 = f(x0);
        f1 = f(x1);

        if (f0 == f1)
        {
            printf("Mathematical Error: Division by zero.\n");
            return -1;
        }

        // Secant formula
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", step, x0, x1, x2, f2);

        x0 = x1;
        x1 = x2;

        step++;

        if (step > N)
        {
            printf("Not convergent within given iterations.\n");
            return -1;
        }
    } while (fabs(f2) > e);

    printf("\nRoot = %.6lf\n", x2);
    return 0;
}