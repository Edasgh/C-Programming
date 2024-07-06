#include <stdio.h>
// gcc sev.c -o e
//.\e.exe

void main()
{
    int rows;
    printf("Enter a number here : ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = rows - i; j >= 0; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");
    }
}

/*
OUTPUT
Enter a number here : 4
    *
   **
  ***
 ****


*/