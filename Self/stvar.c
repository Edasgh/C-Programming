#include <stdio.h>
// Author : Eshita Das
// This file is about static variables in C
int func(int b)
{
    static int myvar = 95;
    // static int myvar;
    printf("The value of the static variable myvar is %d\n", myvar);
    myvar++; // static stores the incremented value to the variable and remembers it irrespective of scope

    return b + myvar;
}

void main()
{
    int b1 = 34;
    int val;
    val = func(b1);
    val = func(b1);
    val = func(b1);
    val = func(b1);
    val = func(b1);

    /* The Output:

    The value of the static variable myvar is 95
    The value of the static variable myvar is 96
    The value of the static variable myvar is 97
    The value of the static variable myvar is 98
    The value of the static variable myvar is 99
    */
}