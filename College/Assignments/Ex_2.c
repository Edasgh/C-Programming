#include <stdio.h>

// enter a number to check if it's even or odd
void main()
{
    int num;
    printf("Enter a number here :\n");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("The number is even\n");
    }
    else
    {
        printf("The number is odd\n");
    }
}