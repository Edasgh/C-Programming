#include <stdio.h>
// gcc thr.c -o a

void main()
{
    int array[12];
    int sum = 0, temp, flag = 0, max;
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

    // bubble sort
    // for (int i = 0; i < 12 - 1; i++)
    // {
    //     flag = 0;
    //     for (int j = 0; j < 12 - 1 - i; j++)
    //     {
    //         if (array[j] < array[j + 1])
    //         {
    //             temp = array[j];
    //             array[j] = array[j + 1];
    //             array[j + 1] = temp;
    //             flag = 1;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         break;
    //     }
    // }

    // selection sort
    // for (int i = 0; i < 12 - 1; i++)
    // {
    //     max = i;
    //     for (int j = i + 1; j < 12; j++)
    //     {
    //         if (array[j] > array[max])
    //         {
    //             max = j;
    //         }
    //     }
    //     if (max != i)
    //     {
    //         temp = array[i];
    //         array[i] = array[max];
    //         array[max] = temp;
    //     }
    // }

    // insertion sort
    for (int i = 0; i < 12; i++)
    {
        temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] < temp)
        {
            // right shifts the element
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    printf("\n\nPrinting the array in descending order :\n");

    for (int i = 0; i < 12; i++)
    {
        printf(" %d ", array[i]);
    }
}