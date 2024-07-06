#include <stdio.h>
// gcc diamond_pattern.c -o a
//.\a.exe

void main()
{
    int num;
    printf("Enter a number to print diamond pattern : ");
    scanf("%d", &num);

    for (int i = 0; i <= num; i++)
    {
        for (int j = 1; j <= (num - i); j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= ((2 * i) - 1); k++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = num; i >= 1; i--)
    {
        for (int j = num - i; j >= 1; j--)
        {
            printf(" ");
        }
        for (int k = (2 * i - 1); k >= 1; k--)
        {
            printf("*");
        }

        printf("\n");
    }
}
/* OUTPUT
Enter a number to print diamond pattern : 6

     *
    ***
   *****
  *******
 *********
***********
***********
 *********
  *******
   *****
    ***
     *

*/
