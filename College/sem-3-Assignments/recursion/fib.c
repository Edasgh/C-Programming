#include <stdio.h>

void printFibonacci(int n)
{
    static int num1 = 0, num2 = 1, nextTerm;

    if (n > 0)
    {
        printf("%d, ", num1);
        nextTerm = num1 + num2;
        num1 = num2;
        num2 = nextTerm;
        printFibonacci(n - 1);
    }
}

void main()
{
    int n;
    printf("Enter the number of terms to print fibonacci sequence : ");
    scanf("%d", &n);

    printf("Fibonacci Series: \n");
    printFibonacci(n);
}