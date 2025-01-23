The `mergeSort` function implements the iterative (bottom-up) version of the merge sort algorithm. Here's a detailed step-by-step explanation of how it works:

### 1. **Function Signature**
```c
void mergeSort(int arr[], int n)
```
- **`arr[]`**: This is the array to be sorted.
- **`n`**: This is the size of the array.

### 2. **Variable Declarations**
```c
int curr_size;  // For current size of subarrays to be merged
int left_start; // For picking starting index of left subarray
```
- **`curr_size`**: Keeps track of the size of the subarrays to be merged. It starts at 1, meaning the algorithm initially merges pairs of elements.
- **`left_start`**: The starting index of the left subarray that will be merged with the right subarray.

### 3. **Outer Loop: Iterating Over Subarray Sizes**
```c
for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
```
- The outer loop iterates over the size of the subarrays. Initially, it starts with subarrays of size 1 (`curr_size = 1`), then doubles in each iteration (`curr_size = 2, 4, 8, ...`) until the size of the subarrays exceeds or equals `n-1`.
- This loop essentially controls the "bottom-up" merging, where subarrays of increasing size are merged together.

### 4. **Inner Loop: Merging Subarrays**
```c
for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
```
- The inner loop iterates over the array and picks the starting index (`left_start`) of the left subarray.
- In each iteration, two subarrays of size `curr_size` are merged:
  - **Left subarray** starts at `left_start` and ends at `min(left_start + curr_size - 1, n - 1)`.
  - **Right subarray** starts at `mid + 1` and ends at `min(left_start + 2 * curr_size - 1, n - 1)`.

### 5. **Finding Midpoint and Right Endpoint**
```c
int mid = min(left_start + curr_size - 1, n - 1);
int right_end = min(left_start + 2 * curr_size - 1, n - 1);
```
- **`mid`**: This is the midpoint of the left subarray.
- **`right_end`**: This is the endpoint of the right subarray.
- Both `mid` and `right_end` are computed with `min` to ensure the indices do not go beyond the array bounds (`n - 1`).

### 6. **Merging Two Subarrays**
```c
merge(arr, left_start, mid, right_end);
```
- This calls the `merge` function, which takes in the array `arr[]`, and the indices `left_start`, `mid`, and `right_end` to merge the two subarrays (`arr[left_start...mid]` and `arr[mid+1...right_end]`).

### 7. **End of the Iterative Merge Sort**
Once the outer loop completes, the array is sorted because it has been progressively divided into smaller subarrays and merged back together in sorted order.

### `merge` function

The `merge` function is responsible for merging two sorted subarrays into one sorted array. Here's how it works:

```c
void merge(int a[], int l, int m, int u)
{
    int i=l, j=m+1, k=0;
    int b[u+1];  // Temporary array for merging

    while(i <= m && j <= u)
    {
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];
    }

    if(i > m)  // If left subarray is exhausted
    {
        while(j <= u)
        {
            b[k++] = a[j++];
        }
    }
    else if(j > u)  // If right subarray is exhausted
    {
        while(i <= m)
        {
            b[k++] = a[i++];
        }
    }

    // Copy the merged data back into the original array
    for (i = l, k = 0; i <= u; i++, k++)
    {
        a[i] = b[k];
    }
}
```

1. **Initialization**: 
   - `i = l`, `j = m + 1`, and `k = 0` are initialized.
   - `b[]` is the temporary array used for merging.

2. **Merging**:
   - The `while` loop compares elements from the left and right subarrays (`a[i]` and `a[j]`) and puts the smaller element into `b[k]`.
   - This continues until one of the subarrays is fully merged.

3. **Appending Remaining Elements**:
   - If there are remaining elements in either subarray, the second `while` loop takes care of appending them to `b[]`.

4. **Copying Back**:
   - Finally, the merged content from the temporary array `b[]` is copied back into the original array `a[]`.

### Final Result

Once all the subarrays are merged in the iterative process, the original array `arr[]` becomes sorted. The `printArray` function is used to print the sorted array after the `mergeSort` completes.

### Example Output

For the input array `{12, 11, 13, 5, 6, 7}`, the output will be:

```
Given array is 
12 11 13 5 6 7 
Sorted array is 
5 6 7 11 12 13
```