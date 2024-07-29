#include <stdio.h>
// gcc fv.c -o a
void main()
{
    int size, sum = 0, avg;
    printf("Enter a number here : ");
    scanf("%d", &size);

    for (int i = 1; i <= size; i++)
    {
        sum += i;
    }

    avg = sum / size;
    printf("\nAverage of numbers from 1 to %d is %d", size, avg);
}