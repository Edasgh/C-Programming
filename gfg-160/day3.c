// User function Template for C

void reverseArray(int arr[], int n)
{
    // Code here
    int arr2[n];
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        arr2[i] = arr[n - 1 - i];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
    }
}