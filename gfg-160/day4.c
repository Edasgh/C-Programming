// User function Template for C

// Function to rotate an array by d elements in counter-clockwise direction.
void rotateArr(int arr[], int n, int d)
{
    // code here
    // Handle case when d > n
    d %= n;

    int temp[n];

    // Copy last n - d elements to the front of temp
    for (int i = 0; i < n - d; i++)
        temp[i] = arr[d + i];

    // Copy the first d elements to the back of temp
    for (int i = 0; i < d; i++)
        temp[n - d + i] = arr[i];

    // to get the final rotated array || reverse the array
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}