/* Iterative C program for merge sort */
#include <stdlib.h>
#include <stdio.h>

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[ub + 1];

    while (i <= mid && j <= ub)
    {
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            b[k++] = a[j++];
        }
    }
    else if (j > ub)
    {
        while (i <= mid)
        {
            b[k++] = a[i++];
        }
    }

    for (int c = lb; c <= ub; c++)
    {
        a[c] = b[c];
    }
}

// Utility function to find minimum of two integers
int min(int x, int y) { return (x < y) ? x : y; }

/* Iterative mergesort function to sort arr[0...n-1] */
void mergeSort(int arr[], int n)
{
    int curr_size;  // For current size of subarrays to be merged
                    // curr_size varies from 1 to n/2
    int left_start; // For picking starting index of left subarray
                    // to be merged

    // Merge subarrays in bottom up manner.  First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        // Pick starting point of different subarrays of current size
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting
            // point of right
            int mid = min(left_start + curr_size - 1, n - 1);

            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(arr, left_start, mid, right_end);
        }
    }
}


/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
void main()
{
    int n;
    printf("Enter the maximum size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Now enter the array elements : \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the value at index = %d : ",i);
        scanf("%d",&arr[i]);
    }
   
    printf("The given array is \n");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("\nThe sorted array (ascending order) is \n");
    printArray(arr, n);
}
