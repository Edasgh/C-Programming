#include <stdio.h>
// gcc five.c -o a
//.\a.exe

void main()
{
    int rows, count = 0;
    printf("Enter a number to print floyd's triangle : ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            count++;
            printf(" %d ", count);
        }
        printf("\n");
    }
}

/*
   OUTPUT
   Enter a number to print floyd's triangle : 4
    1
    2  3
    4  5  6
    7  8  9  10


 */