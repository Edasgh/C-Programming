#include <stdio.h>
// gcc Ex_11.c -o Ex_11
//.\Ex_11.exe
// Author : Eshita Das

void main()
{
    int num, orgNum, d, revNum = 0;
    printf("Enter a number to check if it is a palindrome\n");
    scanf("%d", &num);
    orgNum = num;
    while (num > 0)
    {
        d = num % 10;
        revNum = revNum * 10 + d;
        num /= 10;
    }

    if (revNum == orgNum)
    {
        printf("%d is a palindrome number\n", orgNum);
    }
    else
    {
        printf("%d is not a palindrome number\n", orgNum);
    }
}