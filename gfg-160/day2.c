void pushZerosToEnd(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        // pushing all non-zero elements to the front
        if (arr[i] != 0)
        {
            arr[count] = arr[i];
            //increment count
            count++;
        }
    }

// all the elements will be 0 from count to n
    for (int i = count; i < n; i++)
    {
        arr[i] = 0;
    }
}