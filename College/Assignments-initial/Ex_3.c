#include <stdio.h>

// Enter a number to check if it's divisible by 5 or not
void main()
{
    int num;
    printf("Enter a number to check if it's divisible by 5 or not:\n");
    scanf("%d", &num);

    if (num % 5 == 0)
    {
        printf("%d is divisible by 5\n", num);
    }
    else
    {
        printf("%d is not divisible by 5\n", num);
    }
}