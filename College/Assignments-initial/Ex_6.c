#include <stdio.h>

// program to find leap year
void main()
{
    int fullYear;
    printf("Please enter a full year : ");
    scanf("%d", &fullYear);

    if (fullYear % 4 == 0)
    {
        printf("The year %d is a leap year\n", fullYear);
    }
    else
    {
        printf("The year %d is not a leap year\n", fullYear);
    }
}