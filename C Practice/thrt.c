#include <stdio.h>

//sort an array
void main()
{
  int a[50];
  int size;
  printf("Enter the size of the array : ");
  scanf("%d",&size);
  
  int i=0,j=0,temp,flag=0;
  for(i=0;i<size;i++)
   {
    printf("a[%d] =",i);
    scanf("%d",&a[i]);
   }

  
   for(i=0;i<size;i++)
   {
     printf(" %d ",a[i]);
    }

   
    //bubble sort
  /*
   for(i=0;i<size-1;i++)
   {
     flag = 0;
     for(j=0;j<size-i;j++)
      {
        if(a[j]>a[j+1])
         {
            temp = a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            flag=1;
         }
     
       }

       if(flag==0)
        {
          break;
        }
     }
    */

   int min;
  //selection sort
  
  /* 
  for(i=0;i<size-1;i++)
    {
      min=i;
     for(j=i+1;j<size;j++)
      {
        if(a[j]<a[min])
         {
           min=j;
         }
      }
      
       if(min!=i)
       {
         temp = a[i];
         a[i]=a[min];
         a[min]=temp;
       }
      
    }
   */
   
  //insertion sort
   for(i=1;i<size;i++)
   {
      temp = a[i];
      j=i-1;
      while(j>=0 && a[j]>temp)
      {
        a[j+1] = a[j];
        j--;
      }
      a[j+1]=temp;
   }
   
   printf("\n");
    
    for(i=0;i<size;i++)
   {
     printf(" %d ",a[i]);
    }


}