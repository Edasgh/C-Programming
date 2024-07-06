#include <stdio.h>
// gcc four.c -o a
//.\a.exe

void main()
{

    int rows;
    printf("Enter a number here : ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}

/*
    OUTPUT
    Enter a number here : 5
    1
    12
    123
    1234
    12345



*/