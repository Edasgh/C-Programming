#include <stdio.h>
// gcc pr1.c -o a
//.\a.exe

void multTable(int num)
{
    int i = 1;
    printf("The multiplication table of %d is : \n", num);
    while (i < 11)
    {
        int product = num * i;
        printf("%d * %d = %d\n", num, i, product);
        i++;
    }
}

void main()
{
    int num;
    printf("Enter a number :");
    scanf("%d", &num);

    multTable(num);
}