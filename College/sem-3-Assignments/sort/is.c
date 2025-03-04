#include <stdio.h>

void insertionSort(int a[],int n)
{
    int temp,j;
    for(int i=1;i<n;i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = temp;

    }
}

void main(){
    int n;
    printf("\nInsertion Sort Program\n");
    printf("Enter the max no. of elements to sort : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter value for index = %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nPrinting the array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nNow sorting in ascending order\n");
    insertionSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}