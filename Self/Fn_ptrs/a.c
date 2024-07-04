#include <stdio.h>
// cd Fn_ptrs
//  gcc a.c
//.\a.exe

// function pointers in C || revise pointers & dynamic memory allocation before proceeding

int sum(int a, int b)
{
    return a + b;
}

void main()
{

    int c = sum(30, 24);
    // printf("%d\n", c); // testing the function

    int (*ptr)(int, int);
    ptr = &sum;

    printf("The value of sum is %d\n", (*ptr)(4, 6)); // 10
}