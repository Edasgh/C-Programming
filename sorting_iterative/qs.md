```c
#include <stdio.h>
#include <stdlib.h>

// Partition function as is
int Partition(int a[], int lb, int ub)
{
    int pivot = a[lb], start = lb, end = ub;
    while (start < end)
    {
        while (a[start] <= pivot && start < ub)
        {
            start++;
        }

        while (a[end] > pivot)
        {
            end--;
        }
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

void IterativeQuickSort(int a[], int lb, int ub)
{
    // Create an explicit stack
    int *stack = (int *)malloc(sizeof(int) * (ub - lb + 1));
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
        int loc = Partition(a, lb, ub);

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

    // Free the stack memory
    free(stack);
}

void main()
{
    int a[] = {10, 15, 1, 2, 9, 6, 11};
    int n = sizeof(a) / sizeof(a[0]);
    IterativeQuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
```

### Explanation of Changes:
1. **Stack Replacement**: Instead of calling `QuickSort` recursively, we use an explicit stack to simulate the recursion.
   - The stack holds the indices for the subarrays (low and high bounds).
   - We push the bounds of the subarrays to the stack, process the array, and then push the new bounds (for the left and right sides of the pivot) back onto the stack.

2. **While Loop**: The main loop continues as long as there are subarrays to process, i.e., as long as the stack isn't empty.

3. **Memory Management**: I’ve used `malloc` to allocate memory for the stack and `free` it once we're done. 

This iterative approach effectively removes the need for recursion, while still sorting the array in the same way.