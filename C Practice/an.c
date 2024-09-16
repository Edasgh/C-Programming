#include <stdio.h>

void main()
{
    int n;
    printf("Enter a number here : ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        int i, j, k;
        for (i = 1; i <= n; i++)
        {
            if (i % 2 == 0 && i <= n)
            {
                for (j = 1; j <= i / 2; j++)
                {
                    printf("* ");
                }
                for (k = n - i; k > 0; k--)
                {
                    printf("  ");
                }
                for (j = 1; j <= i / 2; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }
            else if (i == n)
            {
                for (j = 1; j <= i; j++)
                {
                    printf("* ");
                }
                printf("\n");
            }

            
        }

        for (i = n - 1; i >= 1; i--)
        {
            if (i % 2 == 0)
            {
                for (j = i / 2; j >= 1; j--)
                {
                    printf("* ");
                }
                for (k = 1; k <= n - i; k++)
                {
                    printf("  ");
                }
                for (j = i / 2; j >= 1; j--)
                {
                    printf("* ");
                }

                printf("\n");
            }
        }
    }
    else
    {
        printf("\nPattern printing not possible!\n");
    }
}