// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

int binarySearch(int a[], int size)
{
    int search;
    printf("\nEnter the element you want to search : ");
    scanf("%d", &search);
    int l, r, mid;
    l = 0;
    r = size - 1;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (search == a[mid])
        {
            printf("%d is found at location %d", search, mid);
            return mid;
            // if the element is finally found, break out of the loop
            break;
        }
        else if (search < a[mid])
        {
            r = mid - 1;
        }
        else if (search > a[mid])
        {
            l = mid + 1;
        }
    }

    printf("%d is not found in the array", search);
    return -1;
}

void main()
{
    int a[30];
    int size, flag = 0, temp;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int i = 0, j = 0;
    while (i < size)
    {
        printf("Now enter the value at %d : ", i);
        scanf("%d", &a[i]);
        i++;
    }

    for (i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            // if the array is already sorted break out of the loop
            break;
        }
    }

    printf("\n Now printing the sorted array : \n");
    i = 0;
    while (i < size)
    {
        printf(" %d ", a[i]);
        i++;
    }

    int value;
    value = binarySearch(a, size);
}