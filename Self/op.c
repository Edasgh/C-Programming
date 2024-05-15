#include <stdio.h>
#define PI 3.14
int main()
{
    int a = 5;
    const float b = 7.333;
    // PI=2.14;// can't do this cz PI is a constant
    // b=6.22; // can't do this cz b is a constant
    // printf("The value of b is %.2f\n and the value of PI is %.2f",b,PI);
    // printf("The value of a is %d and the value of b is %f\n",a,b);
    // printf("Let's print a backslash \\");
    // printf("Let's print a tab character \t");
    // printf("Let's produce a beep sound \a");

    int subject;
    int math = 15;
    int science = 18;
    int both = 45;
    printf("How many subjects did you pass?: 1. Math only, 2. Science only, 3. Both Math and Science \n");
    scanf("%d", &subject);
    printf("You've chosen the option %d \n", subject);
    //Here is the switch-case statement
    switch (subject)
    {
    case 1:
        printf("You've won %d rupees cz, you've only passed math", math);
        break;
    case 2:
        printf("You've won %d rupees cz, you've only passed science", science);
        break;
    case 3:
        printf("Hurray! you've won %d rupees cz, you've passed both math and science", both);
        break;
    default:
        printf("Hi! kindly choose a valid number...");
    }
    return 0;
}