#include <stdio.h>
// gcc sx.c -o a
void main()
{
    int a, b;
    printf("Enter a number here :");
    scanf("%d", &a);
    printf("Enter another number here :");
    scanf("%d", &b);

    int c, hcf = 0;
    c = a > b ? a : b;

    for (int i = 1; i <= c; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            hcf = i;
        }
    }

    if (hcf == 1)
    {
        printf("\nThe numbers %d and %d are co-prime", a, b);
    }
    else
    {
        printf("\nThe numbers %d and %d are not co-prime", a, b);
    }
}