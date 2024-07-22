#include <stdio.h>
// gcc sum.c -o a
//.\a.exe
void main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    int sum = 0;

    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    printf("The sum of natural numbers till %d is : %d", num, sum);
}