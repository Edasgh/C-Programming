#include <stdio.h>
// gcc perfNum.c -o a
//.\a.exe
void main()
{
    int num;
    printf("Enter a number to check if it's a perfect number :");
    scanf("%d", &num);

    int i = 1, sum = 0;
    while (i < num)
    {
        if (num % i == 0)
        {
            sum += i;
        }
        i++;
    }

    if (sum == num)
    {
        printf("\n%d is a perfect number", num);
    }
    else
    {
        printf("\n%d is not a perfect number", num);
    }
}