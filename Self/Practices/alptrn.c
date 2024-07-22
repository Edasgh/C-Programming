#include <stdio.h>
// gcc alptrn.c -o a
//.\a.exe
void main()
{
    int rows;
    printf("Enter the no. of rows : ");
    scanf("%d", &rows);
    int i = 1, j, k, l;

    while (i <= rows)
    {
        j = rows - i;
        while (j >= 0)
        {
            printf(" ");
            j--;
        }
        k = 1;
        while (k <= i)
        {
            printf("%c", (char)(64 + k));
            k++;
        }
        l = i - 1;
        while (l >= 1)
        {
            printf("%c", (char)(64 + l));
            l--;
        }
        printf("\n");
        i++;
    }
}