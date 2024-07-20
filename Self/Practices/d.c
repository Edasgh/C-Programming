#include <stdio.h>
// gcc d.c -o d
//.\d.exe
void main()
{
    int rows;
    printf("Enter the no. rows you want\n");
    scanf("%d", &rows);
    int i, j, k;
    // upper triangle
    i = 1;
    while (i <= rows)
    {
        j = rows - i;
        while (j >= 0)
        {
            printf(" ");
            j--;
        }
        k = 1;
        while (k <= 2 * i - 1)
        {
            printf("*");
            k++;
        }
        printf("\n");
        i++;
    }
    // lower triangle
    i = rows;
    while (i > 0)
    {
        j = 0;
        while (j <= rows - i)
        {
            printf(" ");
            j++;
        }
        k = 2 * i - 1;
        while (k > 0)
        {
            printf("*");
            k--;
        }
        printf("\n");
        i--;
    }
    // // upper triangle
    // for (int i = 1; i <= rows; i++)
    // {
    //     // spaces
    //     for (int j = rows - i; j >= 0; j--)
    //     {
    //         printf(" ");
    //     }
    //     // stars
    //     for (int k = 1; k <= 2 * i - 1; k++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    // // lower triangle
    // for (int i = rows; i > 0; i--)
    // {
    //     // spaces
    //     for (int j = 0; j <= rows - i; j++)
    //     {
    //         printf(" ");
    //     }
    //     // stars
    //     for (int k = 2 * i - 1; k > 0; k--)
    //     {
    //         printf("*");
    //     }

    //     printf("\n");
    // }
}