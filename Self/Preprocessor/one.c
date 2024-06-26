#include <stdio.h>
#include <string.h>
#include "two.c"
#define PI 3.14
// defining a macro || a preprocessor defined function
#define SQUARE(a) a *a

extern int var; // included from two.c

void main()
{

    printf("Hello this is var , %d \n", var);
    printf("Hello this is the value of PI , %.2f \n", PI);
    int radius = 2;
    float area;
    area = (PI * SQUARE(radius));
    printf("The area of the circle is , %.2f \n", area);
}