#include <stdio.h>
// gcc arr.c -o arr
// .\arr.exe

//function to reverse an array | Ex-5
void arrayRev(int arr[])
{
 int arr2[8];
 for (int i = 0; i <8; i++)
 {
   arr2[i]=arr[7-i];

 }
 for(int j=0;j<8;j++)
 {
    arr[j]=arr2[j];
 }


 
}
//function of average
int avg(int array[])
{
    int sum,avg;
    for(int i=0;i<5;i++)
    {
        printf("The value at %d is %d\n",i,array[i]);
        sum=sum+array[i];
    }
    avg=sum/5;
    // array[0]=465; // if user changes any value here, it gets reflected in the original array
    return avg;
}
int printVal(int *ptr)
{
    for(int i=0;i<8;i++)
    {
        // printf("The value at %d is %d\n",i,ptr[i]);
        printf("The value at %d is %d\n",i,*(ptr+i));
        
    }
    return 0;
}
int sum(int *ptr)
{
    for(int i=0;i<5;i++)
    {
        // printf("The value at %d is %d\n",i,ptr[i]);
        printf("The value at %d is %d\n",i,*(ptr+i));
        
    }
    return 0;
}
//a function which takes multidimensional array as parameter
void func(int arr[2][2])
{
     for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
    {
         printf("The value at %d, %d is %d\n",i,j,arr[i][j]);
        
    }
        
    }
}
void main()
{
    // int marks[4]={4,53,29,45}; // initialization with decalration // 1d array
    // marks[0]=75;
    // marks[2]=90;
    // marks[3]=80;
    // printf("The marks obtained by student 3 is %d\n",marks[2]);
    // marks[2]=79;
    // printf("The marks obtained by student 3 is %d\n",marks[2]);

    // for(int i=0;i<4;i++)
    // {
    //     printf("Enter the value of %dth element of the array\n",i);
    //     scanf("%d",&marks[i]);
    // }
    // for(int i=0;i<4;i++)
    // {
    //     printf("The value of %dth element of the array is %d\n",i,marks[i]);

    // }

    // 2d array
    // int marks[2][4] = {{45, 68, 89, 90}, {89, 88, 45, 60}}; // 2-rows, 4-columns
    // for (int i = 0; i < 2; i++) // now the array will be prnted as a matrix
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         // printf("The value of element of the %dth row and %dth column of the array is %d\n", i, j, marks[i][j]);
    //         printf("%d ",marks[i][j]);
    //     }
    //     printf("\n");
    // }



    //Passing array as an argument to function
    // int arr[]={23,34,45,60,90};
    // printf("The value at index 0 is %d\n",arr[0]);
    // int average;
    // average=avg(arr);
    // printf("The average is, %d\n",average);
    // printf("The value at index 0 is %d\n",arr[0]);


 //Now passing the address of an array as parameter to a function
//  sum(arr);
//  sum(arr);

//Passing multidimensional array as argument/parameter
// int arr2[2][2]={{23,34},{0,1}};
// func(arr2);




//Ex-5 : Array Reversal In C
int arr[]={1,2,4,7,8,68,78,90};
printVal(arr);
arrayRev(arr);
printf("The reversed array is: \n");
printVal(arr);



}