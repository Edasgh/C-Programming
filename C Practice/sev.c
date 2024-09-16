#include <stdio.h>


void main()
{
  int arr[20];
  int size;
  printf("Enter the size of the array : ");
  scanf("%d",&size);

  printf("\nNow enter the elements of the array :\n");
  int i;
  for(i=0;i<size;i++)
  {
    printf("arr[%d] = ",i);
    scanf("%d",&arr[i]);
  }

  
  int sumOdd=0,sumEv=0,cEv=0,cOd=0;

  for(i=0;i<size;i++)
  {
    if(arr[i]%2==0)
    {
     cEv++;
     sumEv+=arr[i];
    }
    else
    {
     cOd++;
     sumOdd+=arr[i];
    }
  }
  printf("\n");
   
  printf("The sum of even numbers is %d\n",sumEv);
  printf("The sum of odd numbers is %d\n",sumOdd);
  printf("The average of even numbers is %d\n",sumEv/cEv);
  printf("The average of odd numbers is %d\n",sumOdd/cOd);

  int largest, second_largest;
  largest = second_largest=0;
  
  for(i=0;i<size;i++)
  {
    if(arr[i]>largest)
    {
     second_largest = largest;
     largest = arr[i];
    }
    else if(arr[i]>second_largest && arr[i]!=largest)
    {
      second_largest = arr[i];
     } 
  }

  printf("%d is the second largest element in the array\n",second_largest); 
  
  


}