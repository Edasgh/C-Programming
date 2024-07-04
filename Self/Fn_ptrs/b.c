#include <stdio.h>

int mult(int a, int b)
{
    return a * b;
}
void greetHelloAndExecute(int (*fptr)(int, int))
{
    printf("Hello user!\n");
    printf("The multiplication of 6 and 4 is %d\n", fptr(6, 4)); // here fptr or mult is the callback function
}
void main()
{

    int (*ptr)(int, int);
    ptr = &mult;
    greetHelloAndExecute(ptr);
}