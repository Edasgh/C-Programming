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


Let's go through the program step by step to understand how the **Iterative QuickSort** works.

---

### **Step 1: Input Array**
The program starts with an input array:
```c
int a[] = {10, 15, 1, 2, 9, 6, 11};
```
The size of the array is calculated as:
```c
int n = sizeof(a) / sizeof(a[0]); // n = 7
```

---

### **Step 2: Partition Function**
The `Partition` function is responsible for dividing the array around a **pivot element**. Here’s how it works:

1. The **pivot** is chosen as the first element of the array:
   ```c
   int pivot = a[lb];
   ```
2. Two pointers are initialized:
   - `start = lb` (points to the first element of the subarray).
   - `end = ub` (points to the last element of the subarray).

3. The goal is to rearrange the elements such that:
   - Elements smaller than or equal to the pivot are to its left.
   - Elements larger than the pivot are to its right.

4. **While Loop**: This loop runs until `start` and `end` cross each other:
   - Increment `start` until you find an element greater than the pivot.
   - Decrement `end` until you find an element smaller than or equal to the pivot.
   - Swap the elements at `start` and `end` if `start < end`.

5. Finally, place the pivot in its correct position by swapping it with the element at the `end` index:
   ```c
   a[lb] = a[end];
   a[end] = pivot;
   ```
   The function returns the `end` index, which is the pivot's final position.

---

### **Step 3: Iterative QuickSort**
Instead of recursion, this function uses an **explicit stack** to manage the subarray bounds:

#### **3.1 Initialize the Stack**
- Allocate memory for the stack:
  ```c
  int *stack = (int *)malloc(sizeof(int) * (ub - lb + 1));
  ```
  This stack can hold the bounds of all possible subarrays.

- Push the initial bounds (entire array) onto the stack:
  ```c
  stack[++top] = lb; // Push lower bound
  stack[++top] = ub; // Push upper bound
  ```

---

#### **3.2 Main Loop**
The loop runs until the stack is empty:
1. **Pop the Bounds**: Retrieve the current subarray's bounds from the stack:
   ```c
   ub = stack[top--];
   lb = stack[top--];
   ```

2. **Partition the Subarray**: Call the `Partition` function to rearrange the subarray and find the pivot position:
   ```c
   int loc = Partition(a, lb, ub);
   ```

3. **Push Left Subarray**: If there are elements to the left of the pivot, push their bounds onto the stack:
   ```c
   if (loc - 1 > lb) {
       stack[++top] = lb;
       stack[++top] = loc - 1;
   }
   ```

4. **Push Right Subarray**: If there are elements to the right of the pivot, push their bounds onto the stack:
   ```c
   if (loc + 1 < ub) {
       stack[++top] = loc + 1;
       stack[++top] = ub;
   }
   ```

---

#### **3.3 End of Sorting**
When the stack is empty, all subarrays have been processed, and the array is sorted. Free the allocated memory for the stack:
```c
free(stack);
```

---

### **Step 4: Print the Sorted Array**
After sorting, the main function iterates through the array and prints the elements:
```c
for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
}
```

For the input array `{10, 15, 1, 2, 9, 6, 11}`, the output will be:
```
1 2 6 9 10 11 15
```

---

### **Key Points**
1. **Explicit Stack**: Replaces recursion, simulating the process of dividing the array into smaller subarrays.
2. **Partitioning**: Rearranges the array into two parts, with the pivot in its correct position.
3. **Efficiency**: This approach eliminates the risk of stack overflow caused by too many recursive calls.

Let me know if you'd like clarification on any specific part!