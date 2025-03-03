#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
        return n;

    return n * factorial(n - 1);
}

void main()
{
    int n, fact;
    printf("Enter the number to print factorial : ");
    scanf("%d", &n);
    fact = factorial(n);
    printf("\nThe factorial of %d is %d", n, fact);
}