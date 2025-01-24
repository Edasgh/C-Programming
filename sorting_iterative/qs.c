// An iterative implementation of quick sort
#include <stdio.h>
#include <stdlib.h>
/* This function is same in both iterative and recursive*/
int partition(int a[], int lb, int ub)
{
    int pivot = a[lb], start = lb, end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
        {
            int t = a[start];
            a[start] = a[end];
            a[end] = t;
        }
    }

    int t = a[lb];
    a[lb] = a[end];
    a[end] = t;
    return end;
}

void quickSortIterative(int a[], int lb, int ub)
{
    // Create an explicit stack
    int stack[(ub-lb)+1];
    int top = -1;

    // Push the initial bounds of the array
    stack[++top] = lb;
    stack[++top] = ub;

    // Keep processing the stack until it is empty
    while (top >= 0)
    {
        // Pop the upper and lower bounds
        ub = stack[top--];
        lb = stack[top--];

        // Partition the array and get the pivot index
        int loc = partition(a, lb, ub);

        // Push the left side of the partition to the stack
        if (loc - 1 > lb)
        {
            stack[++top] = lb;
            stack[++top] = loc - 1;
        }

        // Push the right side of the partition to the stack
        if (loc + 1 < ub)
        {
            stack[++top] = loc + 1;
            stack[++top] = ub;
        }
    }
}

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
    printf("\nPrinting the array\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
void main()
{
   int n;
   printf("Enter the maximum size of the array : ");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the values of the array : \n");
   for(int i=0;i<n;i++)
   {
    printf("Enter the value at index = %d : ",i);
    scanf("%d",&arr[i]);
   }
   printArr(arr, n);
   quickSortIterative(arr, 0, n - 1);
   printf("\nThe sorted array (ascending order ) :\n");
   printArr(arr, n);
    
}
