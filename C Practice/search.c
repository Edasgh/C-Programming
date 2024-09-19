#include <stdio.h>
#include <stdlib.h>
#define MAX 50
// gcc search.c -o a
void LinS(int a[],int size,int search)
{
    int i,flag=0;
    for(i=0;i<size;i++)
    {
       if(a[i]==search)
       {
        printf("%d is present at index : %d in the array.\n",search,i);
        flag=1;
        break;
       }
    }

    if(flag==0)
    {
        printf("%d is not found in the array.\n",search);
    }

}

int binS(int a[], int size, int search)
{
    //sorting the array
    int i,j,temp;
    for(i=0;i<size;i++)
    {
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;

    }

    int l,r,mid;
    l=0;
    r=size-1;

    while(l<r)
    {
        mid = (l+r)/2;
        if(a[mid]==search)
        {
            return mid;
        }
        else if(a[mid]>search)
        {
            r=mid-1;
        }
        else if(a[mid]<search)
        {
            l=mid+1;
        }
    }

    return -1;
}

int main()
{
    int a[MAX];
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    printf("\nNow enter the values :\n");
    for(int i=0;i<n;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    printf("\nNow printing the values :\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
        
    }


    int search,op;

    while(1)
    {
    printf("\nEnter a number to search in the array : ");
    scanf("%d",&search);

    printf("\nSelect a searching method (1. Linear Search , 2. Binary Search , 3.exit) : ");
    scanf("%d",&op);

    int index;

    switch (op)
    {
    case 1:
        LinS(a, n, search);
        break;
    case 2:
        index = binS(a, n, search);
        if (index == -1)
        {
            printf("%d is not found in the array.\n", search);
        }
        else
        {
            printf("%d is found at index %d in the array.\n", search, index);
        }
        break;
    case 3:
        exit(0);
        break;
    
    default:
        printf("Invalid Option!");
    }
   
    }


    return 0;
}