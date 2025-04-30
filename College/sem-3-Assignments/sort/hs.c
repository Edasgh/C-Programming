#include <stdio.h>

void maxHeapify(int a[], int n, int i)
{
    int largest = i, left = (2 * i) + 1, right = (2 * i) + 2;

    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }

    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        // Swap largest & i
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        maxHeapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    // Build Max Heap
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        maxHeapify(a, n, i);
    }

    // deletion
    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxHeapify(a, i, 0); 
    }
}

void main()
{
    int n;
    printf("\nHeap Sort Program\n");
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    heapSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

}
