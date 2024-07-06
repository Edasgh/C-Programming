#include <stdio.h>
// gcc four.c -o a
// .\a.exe

// 1*2 + 2*3 + 3*4 + 4*5+.....N terms
void main()
{
    int num, sum = 0;
    printf("Enter a number here : ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        sum += (i * (i + 1));
        printf("%d * %d = %d \n", i, (i + 1), (i * (i + 1)));
    }

    printf("The total sum of the series is : %d\n", sum);

    /*
        OUTPUT :
        Enter a number here : 4 (input)
        1 * 2 = 2
        2 * 3 = 6
        3 * 4 = 12
        4 * 5 = 20
        The total sum of the series is : 40

    */
}