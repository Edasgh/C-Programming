#include <stdio.h>

// gcc revNum.c -o a
//.\a.exe

void main()
{
    int num, n, d, sum = 0;
    printf("Enter a number : ");
    scanf("%d", &num);
    n = num;

    // while (n > 0)
    // {
    //     d = n % 10;
    //     sum = (sum * 10) + d;
    //     n /= 10;
    // }

    for (n = num; n > 0; n /= 10)
    {
        d = n % 10;
        sum = sum * 10 + d;
    }

    printf("The reverse of %d is %d", num, sum);
}