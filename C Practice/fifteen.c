#include <stdio.h>

void linearSearch(int a[],int size,int search)
{
  int flag=0,i;
 for(i=0;i<size;i++)
{
  if(a[i]==search)
   {
    printf("\nVia linear search method : %d is present at the index %d in the array",search,i);
    flag=1;
    break;
   }
}

if(flag==0)
{
 printf("\nVia linear search method : The number %d is not found in the array",search);
}

}

int binarySearch(int a[],int size, int search)
{
  //sort the array
  //bubble sort
  /* int i,j,temp,flag=0;
  for(i=0;i<size-1;i++)
   {
     flag =0;
    for(j=0;j<(size-1)-i;j++)
     {
       if(a[j]>a[j+1])
        {
          temp = a[j];
          a[j]=a[j+1];
          a[j+1] = temp;
          flag =1;
        }
     }
     
       if(flag==0)
         {
           break;
         }
    }
   */
  //selection sort
/* int i,j,temp,min;
 for(i=0;i<size-1;i++)
  {
    min=i;
   for(j=i+1;j<size;j++)
    {
       if(a[j]<a[min])
        {
          min =j;
         }
    }

    if(min!=i)
    {
      temp = a[i];
      a[i]=a[min];
      a[min] = temp;
    }
  }
*/
 //insertion sort
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
   a[j+1] = temp;
 }

   int r,l,mid;
   r=size-1;
   l=0;
   while(l<r)
   {
   mid = (l+r)/2;
   if(search==a[mid])
    {
      return mid;
    }
     else if(search<a[mid])
     {
       r = mid-1;
     }
     else if(search>a[mid])
    {
      l = mid+1;
     }
   }
  
  return -1;

}

int main()
{
int a[50];
int size;
printf("Enter the size of the array:");
scanf("%d",&size);

int i=0;
for(i=0;i<size;i++)
{
  printf("a[%d] = ",i);
  scanf("%d",&a[i]);
}

int search;
printf("Enter the number you want to search for : ");
scanf("%d",&search);

//linearSearch(a,size,search);

 int index;
 index = binarySearch(a,size,search);

 if(index==-1)
 {
 printf("\nVia binary search method : %d not found",search); 
 }
 else
 {
  printf("\nVia binary search method : %d found at index=%d",search,index);
}

return 0;
}