#include <stdio.h>
// gcc three.c -o a
//.\a.exe

void main()
{
    int n, num, d, count = 0;
    printf("Enter a number to count digits\n");
    scanf("%d", &n);
    num = n;

    while (n > 0)
    {
        d = n % 10;
        count++;
        n /= 10;
    }

    printf("The no. of digits in %d is %d\n", num, count);

    /*
        OUTPUT : Enter a number to count digits
        344 (input)
        The no. of digits in 344 is 3

    */
}