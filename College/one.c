#include <stdio.h>
// gcc one.c -o a
//.\a.exe

void main()
{
    int i, j, mode = 0, num, count = 0, sum = 0;
    printf("\nSelect what to do :\n");
    printf("Enter 1 to print prime numbers from 1 to Your entered Number\nEnter 2 to print perfect numbers from 1 to Your entered Number\n");
    scanf("%d", &mode);
    printf("Now , Enter a number : ");
    scanf("%d", &num);

    switch (mode)
    {
    case 1:

        printf("printing all the prime numbers from 1 to %d\n", num);
        for (i = 1; i <= num; i++)
        {

            for (j = 1; j <= i; j++)
            {
                if (i % j == 0)
                {
                    count++;
                }
            }

            if (count == 2)
            {
                printf("%d\n", i);
            }

            count = 0;
        }
        break;
    case 2:

        printf("printing all the perfect numbers from 1 to %d\n", num);
        for (i = 1; i <= num; i++)
        {

            for (j = 1; j <= i; j++)
            {
                if (i % j == 0 && j != i)
                {
                    sum += j;
                }
            }

            if (sum == i)
            {

                printf("%d\n", i);
            }
            sum = 0;
        }
        break;

    default:
        printf("Invalid option\n");
        break;
    }
}

/*
OUTPUT

Select what to do :
Enter 1 to print prime numbers from 1 to Your entered Number
Enter 2 to print perfect numbers from 1 to Your entered Number
1
Now , Enter a number:6
printing all the prime numbers from 1 to 6
2
3
5
PS C:\Users\edas2\Desktop\C Programming\College> .\a.exe

Select what to do :
Enter 1 to print prime numbers from 1 to Your entered Number
Enter 2 to print perfect numbers from 1 to Your entered Number
2
Now , Enter a number:35
printing all the perfect numbers from 1 to 35
6
28


 */