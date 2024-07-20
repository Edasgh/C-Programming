#include <stdio.h>
// gcc b.c -o b
//.\b.exe

void main()
{
    int num;
    printf("Enter a number :");
    scanf("%d", &num);
    int sum = 0, product = 1;
    int i = 1, j = 1;

    // for (int i = 1; i <= num; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         product *= i;
    //     }

    //     printf("%d ^ %d = %d\n", i, i, product);
    //     sum += product;
    //     product = 1;
    // }

    while (i <= num)
    {
        j = 1;
        while (j <= i)
        {
            product = product * i;
            j++;
        }
        printf("%d ^ %d = %d\n", i, i, product);
        sum = sum + product;
        product = 1;
        i++;
    }

    printf("sum = %d\n", sum);
}