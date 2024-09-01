#include <stdio.h>

struct complex{
 float real;
 float imaginary;
};

void main()
{
    // int size=12;
    // int a[size];
    // for(int i=0;i<size;i++)
    // {
    //     if(i==0)
    //     {
    //         a[i]=1;
    //     }
    //     else
    //     {
    //         a[i]=a[i-1]+3;
    //     }
    // }

    // printf("\nPrinting the array : \n");
    // for(int i=0;i<size;i++)
    // {
    //    printf(" %d ",a[i]);
    // }

    // int num;
    // printf("Enter a number here : ");
    // scanf("%d",&num);

    // int i=0,j=0,product=1;
    // for(i=1;i<=num;i++)
    // {
    //     product*=i;
    // }

    // printf("Factorial of %d is %d",num,product);

    // struct complex num1,num2;
    // num1.real=2;
    // num1.imaginary=1;


    //second largest element in an array
     int size;
     printf("Enter the size of the array : ");
     scanf("%d",&size);

     int a[size];

     for(int i=0;i<size;i++)
     {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
     }

     printf("Now printing the array : ");
     for(int i=0;i<size;i++)
     {
        printf(" %d ",a[i]);
     }

     int max=0,min,max2=0,temp;
     for (int i = 1; i < size; i++)
     {
       max=a[i-1];
       max2=a[i];

       if(max<max2)
       {
        max2=max;
         max = a[i];


       }
        
     }

    //  int sl;

    //  for (int i = 0; i < size; i++)
    //  {
       

    //      if (a[i] < max && a[i]>min)
    //      {
    //          sl = a[i];
    //      }

        
    //  }

     printf("\n %d is the second largest element in the array",max2);
}