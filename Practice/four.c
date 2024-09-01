#include <stdio.h>

void printArr(int a[],int size)
{
int i=0;
for(i=0;i<size;i++)
{
    printf(" %d ",a[i]);

}
}

void sortDes(int a[],int size)
{
    //bubble sort
    // int i=0,j=0,temp;
    // for(i=0;i<size-1;i++)
    // {
    //     for(j=0;j<(size-1)-i;j++)
    //     {
    //         if(a[j]<a[j+1])
    //         {
    //             temp = a[j];
    //             a[j]=a[j+1];
    //             a[j+1]=temp;
    //         }
    //     }
    // }

    //selection sort
    // int i=0,j=0,max,temp;
    // for(i=0;i<size-1;i++)
    // {
    //     max=i;
    //     for(j=i+1;j<size;j++)
    //     {
    //         if(a[j]>a[max])
    //         {
    //             max=j;
    //         }
    //     }
    //     if(max!=i)
    //     {
    //         temp=a[i];
    //         a[i]=a[max];
    //         a[max]=temp;
    //     }
    // }


    //insertion sort
    int i=0,j=0,temp;
    for(i=0;i<size;i++)
    {
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]<temp)
        {
            a[j+1]=a[j];
            j--;

        }
        a[j+1]=temp;
    }

}

void main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    if(size!=0)
    {
    int a[size];
    printf("Now enter the elements of the array\n");
    int i=0;
    for(i=0;i<size;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);

    }
    printf("\nSorting the array in descending order\n");
    sortDes(a,size);
    printArr(a,size);

    }
    else
    {
     printf("Invalid array size");
    }

}