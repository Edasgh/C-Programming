#include <stdio.h>
// gcc pattern.c -o a
void main()
{
    int rows;
    printf("Enter the no. of rows : ");
    scanf("%d", &rows);
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j <= rows - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    /*
Enter the no. of rows : 3
   *
  ***
 *****

    */
}