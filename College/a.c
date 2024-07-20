#include <stdio.h>

void main()
{
    int num, k;
    int i = 1;
    printf("Enter the no. of rows here : ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        for (k = 1; k <= i; k++)
        {

            if (i > 2 && k > 1 && k < i && i < num)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }

        printf("\n");
    }
}