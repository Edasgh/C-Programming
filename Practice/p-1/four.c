#include <stdio.h>


int binS(int a[],int n, int search)
{
    int l=0;
    int r=n-1;
    int mid;
    while(l<r)
    {
      mid = (l+r)/2;
      if(search == a[mid])
      {
         return mid;
      }
      else if(search>a[mid])
      {
        l = mid+1;
      }
      else if(search<a[mid])
      {
        r = mid -1 ;
      }
    }
    return -1;

}

void main()
{
    int arr[]={3,34,56,7,8,9,12,23};
    int search =39;
    // int flag =0;

    // for(int i=0;i<8;i++)
    // {
    //     if(arr[i]==search)
    //     {
    //       printf("%d is found at index %d",search,i);
    //       flag =1;
    //       break;

    //     }
    // }

    // if(flag == 0)
    // {
    //     printf("%d is not found inside the array ",search);
    // }
    int min,temp;

    for(int i=0;i<8-1;i++)
    {
        min = i;
        for(int j=i+1;j<8;j++)
        {

            if(arr[j]<arr[min])
            {
                min=j;
            }

        }
        if(min!=i)
        {
           temp = arr[i];
           arr[i]=arr[min];
           arr[min]=temp;
        }
    }

   
    
}