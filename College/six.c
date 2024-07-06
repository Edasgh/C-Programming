#include <stdio.h>
// gcc six.c -o b
//.\b.exe
void main()
{
    int rows;
    printf("Enter a number here : ");
    scanf("%d", &rows);

    for (int i = rows; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}

/*   OUTPUT
    Enter a number here : 5
    *****
    ****
    ***
    **
    *


*/