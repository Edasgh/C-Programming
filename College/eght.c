#include <stdio.h>
// gcc eght.c -o b
//.\b.exe

void main()
{
    int rows;
    printf("Enter a number here : ");
    scanf("%d", &rows);

    for (int i = rows; i >= 1; i--)
    {
        for (int j = 0; j <= rows - i; j++)
        {
            printf(" ");
        }
        for (int k = i; k >= 1; k--)
        {
            printf("*");
        }
        printf("\n");
    }
}

/*
OUTPUT
Enter a number here : 5
 *****
  ****
   ***
    **
     *

*/