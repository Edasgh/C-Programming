// Function to find the next permutation
void nextPermutation(int arr[], int n)
{
    // code here
    int i, j, temp;
    int arr1[n];

    // find first decreasing element
    // traverse right to left
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
            break;
    }

    if (i < 0)
    {
        // reverse the array
        int k, l;
        for (k = 0; k < n; k++)
        {
            arr1[n - 1 - k] = arr[k];
        }
        for (k = 0; k < n; k++)
        {
            arr[k] = arr1[k];
        }
    }
    else
    {
        //traverse from right to left
        for (j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[i])
                break;
        }
        // swap arr[j] & arr[i]
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;

        // reverse the array from i+1 to n
        for (int k = i + 1; k < n; k++)
        {
            arr1[n - 1 - k] = arr[k];
        }

        for (int k = n - 1; k >= i + 1; k--)
        {
            arr[n - k + i] = arr1[n - 1 - k];
        }
    }
}