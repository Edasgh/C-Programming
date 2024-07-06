#include <stdio.h>
// gcc two.c -o a
//.\a.exe
void main()
{

    int rows;
    printf("Enter a number to print pattern\n");
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++)
    {
        for (int j = (rows - i); j >= 0; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            printf("*");
        }
        printf("\n");
    }

    /*

    Enter a number to print pattern
    5
     *
    ***
   *****
  *******
 *********

     */
}