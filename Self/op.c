#include <stdio.h>
#define PI 3.14 // This is a constant
// gcc op.c -o op

float takeValue() // the function to take value to convert
{
    float val;
    printf("\nNow enter a value for conversion\n");
    scanf("%f", &val);
    return val;
}
void conversion()
{
    float kmToMile = 0.62137119, inchToFoot = 0.0833333, cmToInch = 0.393701, pndToKg = 0.453592, inchToM = 0.0254;
    int mode;
    printf("Select a conversion mode: 1. kms to miles, 2. inches to feet, 3. cms to inches, 4. pound to kgs, 5. inches to meters\n");
    scanf("%d", &mode);
    float val;
    switch (mode)
    {
    case 1:
        val = takeValue();
        printf("%.2f km(s) in mile(s) is/are %.4f\n", val, val * kmToMile);
        break;
    case 2:
        val = takeValue();
        printf("%.2f  inch(es) in foot/feet is/are %.4f\n", val, val * inchToFoot);

        break;
    case 3:
        val = takeValue();
        printf("%.2f  cm(s) in inch(es) is/are %.4f\n", val, val * cmToInch);

        break;
    case 4:
        val = takeValue();
        printf("%.2f  pound(s) in kg(s) is/are %.4f\n", val, val * pndToKg);
        break;
    case 5:
        val = takeValue();
        printf("%.2f  inch(es) in meter(s) is/are %.4f\n", val, val * inchToM);
        break;

    default:
        printf("Choose a valid number to select conversion mode\n");
        break;
    }
}

// recursive function to get fibonacci series  //execution time : 3.42 secs
int fib_recursive(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}
// iterative function to get fibonacci series  //execution time : 2.45 secs
int fib_iterative(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
    {

        return a;
    }
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
void main()
{
    // int a = 5;
    // const float b = 7.333;
    // PI=2.14;// can't do this cz PI is a constant
    // b=6.22; // can't do this cz b is a constant
    // printf("The value of b is %.2f\n and the value of PI is %.2f",b,PI);
    // printf("The value of a is %d and the value of b is %f\n",a,b);
    // printf("Let's print a backslash \\");
    // printf("Let's print a tab character \t");
    // printf("Let's produce a beep sound \a");

    /////////QUIZ/////////
    //    to convert kilometers to miles
    //  to convert inches to foot
    //  to convert centimeters to inches
    //  to convert pounds to kgs
    //  to convert inches to meters

    // conversion();

    /////////////////

    // recursive function: fib_recursive
    // iterative function: fib_iterative
    int num, fib_val;
    printf("Enter a number to see fibonacci value of\n");
    scanf("%d", &num);
    // fib_val=fib_recursive(num);
    fib_val = fib_iterative(num);
    printf("The %dth fibonacci number is %d", num, fib_val);
}