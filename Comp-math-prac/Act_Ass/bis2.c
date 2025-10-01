#include <stdio.h>
#include <math.h>

// problem-2 :   2x - 3sinx - 5 = 0

// Function definition: f(x) = 2x - 3sinx - 5
float f(float x)
{
    return ((2*x) - (3*sinf(x)) - 5);
}

int main()
{
    float x1, x2, xmid, accuracy;
    int k = 1;

    // Take interval input until f(x1)*f(x2) < 0
    do
    {
        printf("\nEnter the initial guess for x1 (-ve)): ");
        scanf("%f", &x1);
        printf("Enter the initial guess for x2 (+ve)): ");
        scanf("%f", &x2);

        if (f(x1) * f(x2) > 0)
        {
            printf("\nRoot is not covered in the given interval. Try again...\n");
        }
    } while (f(x1) * f(x2) > 0);

    // Take accuracy
    // 0.0001 -> 4 decimal points accuracy
    printf("\nEnter the accuracy: ");
    scanf("%f", &accuracy);
    accuracy = fabs(accuracy);

    // Start Bisection Method loop
    do
    {
        xmid = (x1 + x2) / 2.0;

        printf("\nIteration %d :", k++);
        printf("\tx1=%.6f  x2=%.6f  xmid=%.6f  f(xmid)=%.6f  |x1-x2|=%.6f",
               x1, x2, xmid, f(xmid), fabs(x1 - x2));

        // Update interval
        if (f(xmid) < 0)
            x1 = xmid;
        else
            x2 = xmid;

    } while (fabs(x1 - x2) > accuracy);

    printf("\n\nApproximate Root = %.6f\n", xmid);

    return 0;
}