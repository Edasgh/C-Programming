#include <stdio.h>
// gcc two.c -o a
void main()
{

    int array[12];
    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        if (i == 0)
        {
            array[i] = 1;
        }
        else
        {
            array[i] = sum + 3;
        }
        sum = array[i];
    }

    for (int i = 0; i < 12; i++)
    {
        printf(" %d ", array[i]);
    }
}