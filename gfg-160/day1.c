int secondLargest(int arr[],int n)
{
    int max = 0;
    int sec_max = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            sec_max = max;
            max = arr[i];
        }
        else if(arr[i]>sec_max && arr[i]<max)
        {
            sec_max = arr[i];
        }
    }

    if(sec_max==0 || sec_max==max)
    {
        return -1;
    }

    return sec_max;

}