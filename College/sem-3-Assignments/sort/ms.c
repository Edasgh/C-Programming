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
    int a[] ={15,5,24,8,1,3,16,10,20};
    MergeSort(a,0,8);
    for(int i=0;i<=8;i++)
    {
        printf("%d ",a[i]);
    }

}