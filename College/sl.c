#include <stdio.h>
// gcc sl.c -o a
void main()
{
    int arr[] = {21, 34, 12, 67, 8, 9, 20};
    int largest = 0, largestI, sLargest, temp;

    for (int i = 0; i < 7; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            largestI = i;
        }
    }

    for (int i = largestI; i < 7; i++)
    {
        arr[i] = arr[i + 1];
    }

    for (int i = 0; i < 6; i++)
    {

        printf(" %d ", arr[i]);
    }
    largest = 0;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    printf("\nThe second largest element in the array is %d", largest);
}