#include <stdio.h>
// gcc qs.c -o a
int Partition(int a[], int lb, int ub)
{
    int pivot = a[lb], start = lb, end = ub;
    while (start < end)
    {
        while (a[start] <= pivot && start < ub) // Ensure start does not exceed bounds
        {
            start++;
        }

        while (a[end] > pivot) // Ensure end does not go below bounds
        {
            end--;
        }
        if (start < end)
        {
            // Swap the start & end elements
            int t = a[start];
            a[start] = a[end];
            a[end] = t;
        }
    }

    // Place the pivot in its correct position
    // swap a[lb] & a[end] 
    int t = a[lb];
    a[lb] = a[end];
    a[end] = t;

    return end;
}

void QuickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = Partition(a, lb, ub);
        QuickSort(a, lb, loc - 1);
        QuickSort(a, loc + 1, ub);
    }
}

void main()
{
    int a[] = {10, 15, 1, 2, 9, 6, 11};
    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
