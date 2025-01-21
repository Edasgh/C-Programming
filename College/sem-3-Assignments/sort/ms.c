// gcc ms.c -o a
#include <stdio.h>


void Merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid+1, k=lb;
    int b[ub+1];
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        {
           b[k] = a[i];
           i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else if(j>ub)
    {
        while(i<=mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }


    for(int l=lb;l<=ub;l++)
    {
        a[l] = b[l];
    }



}

void MergeSort(int a[],int lb, int ub)
{
    if(lb < ub)
    {
       int mid = (lb+ub)/2;
       MergeSort(a,lb,mid);
       MergeSort(a,mid+1,ub);
       Merge(a,lb,mid,ub);
    }
}

void main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the values in the array : \n");
    int a[n];
    for (int i = 0; i <n; i++)
    {
        printf("Enter value at index = %d\n", i);
        scanf("%d",&a[i]);
    }
    MergeSort(a,0,n);
    printf("\nSorting in ascending order using merge sort\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}