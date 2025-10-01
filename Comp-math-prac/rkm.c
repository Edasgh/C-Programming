#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fd(float x, float y)
{
    return x + powf(y,2.0);
}
// 2nd order
// y = yn-1 + k
// x = xn-1 + h
// k1 = h*fd(x,y)
// k2 = h*fd(x+h,y+k1)
// k = 1/2 * (k1+k2)
float evaluate2ndOrderRK(float x, float y, float h, float valx)
{
    float y1 = y, x1 = x, k1, k2, k;
    int i = 0;
    while (1)
    {
        if (fabsf(valx - x1) < 0.001)
            break;

        k1 = h * fd(x1, y1);
        k2 = h * fd(x1 + h, y1 + k1);
        k = 0.5 * (k1 + k2);
        printf("step %d -> k1 = %f, k2 = %f, k=%f\n", i, k1, k2, k);

        y1 = y1 + k;
        x1 = x1 + h;
        i++;
    }
    return y1;
}

// 4th order
//  y = yn-1 + k
//  x = xn-1 + h
// k1 = h*fd(x,y)
// k2 = h*fd(x+h/2,y+k1/2)
// k3 = h*fd(x+h/2,y+k2/2)
// k4 = h*fd(x+h,y+k3)
// k = 1/6 * (k1+2k2+2k3+k4)
float evaluate4thOrderRK(float x, float y, float h, float valx)
{
    float x1 = x, y1 = y, k1, k2, k3, k4, k;
    int i=0;
    while (1)
    {
        if (fabsf(valx - x1) < 0.001)
            break;

        k1 = h * fd(x1, y1);
        k2 = h * fd(x1 + (h / 2), y1 + (k1 / 2));
        k3 = h * fd(x1 + (h / 2), y1 + (k2 / 2));
        k4 = h * fd(x1 + h, y1 + k3);
        k = 0.167 * (k1 + 2 * k2 + 2 * k3 + k4);
        printf("step %d -> k1 = %f, k2 = %f, k=%f\n", i, k1, k2, k);

        y1 = y1 + k;
        x1 = x1 + h;
        i++;
    }

    return y1;
}

// given
// x initial, y initial, h value, the value to find y x=... , y=?
int main(int argc, char *argv[])
{
    printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    // float x, y, h, valx;
    // printf("Enter the initial value of x : ");
    // scanf("%f", &x);
    // printf("Enter the initial value of y=f(%f) : ", x);
    // scanf("%f", &y);

    // printf("Enter the value of h (step size) : ");
    // scanf("%f", &h);

    // printf("Enter the x value to find f(x) : ");
    // scanf("%f", &valx);

    // // float result = evaluate2ndOrderRK(x, y, h, valx);
    // // printf("The result of f(%f) via 2nd order runge-kutta method is : %f ", valx, result);


    // float result = evaluate4thOrderRK(x, y, h, valx);
    // printf("The result of f(%f) via 2nd order runge-kutta method is : %f ", valx, result);
    return 0;
}
