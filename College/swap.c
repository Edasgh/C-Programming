#include <stdio.h>
// gcc swap.c -o a
void main()
{
    int a = 10;
    int b = 23;

    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}