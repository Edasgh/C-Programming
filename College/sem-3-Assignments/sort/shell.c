// gcc shell.c -o a
#include <stdio.h>

void Shell_sort(int a[], int n)
{
    for (int gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            for (int j = i - gap; j >= 0; j = j - gap)
            {
                if (a[j + gap] > a[j])
                {
                    break;
                }
                else
                {
                    // swap
                    int t = a[j + gap];
                    a[j + gap] = a[j];
                    a[j] = t;
                }
            }
        }
    }
}

void main()
{
    int a[] = {23, 7, 15, 19, 31, 29, 9, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    Shell_sort(a, n);
    //print
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}