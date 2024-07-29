#include <stdio.h>
// gcc sv.c -o a
void main()
{
    // calculate factorial of a given number
    //  int num, fact = 1;
    //  printf("Enter a number here : ");
    //  scanf("%d", &num);

    // for (int i = num; i >= 1; i--)
    // {
    //     fact *= i;
    // }

    // printf(" %d! = %d", num, fact);
    /////////////////////////////////////////////////////////
    // int i = 7;
    // float f = 5.5;
    // char c = 'w';

    // printf("%d\n", ((i >= 6) && (c == 'w')));      // 1
    // printf("%d\n", ((c != 'p') && (i + f) <= 10)); // 0

    /////////////////////////////////////////////////////////////////////////

    // int a = 6, b = 8, c;
    // c = (a++) + (++b) + (++b);
    // printf("a = %d, b = %d , c = %d ", a, b, c);
    // a = 7, b = 10 , c = 25

    /////////////////////////////////////////////////////////////////////////////
    int a, b = 0;
    static int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (a = 0; a < 10; ++a)
    {
        if ((a % 2) == 0)
        {
            b += c[a];
        }
    }

    printf("%d", b); // 25
}