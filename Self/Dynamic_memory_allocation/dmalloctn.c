#include <stdio.h>
#include <stdlib.h> //a must for using functions : malloc() , calloc() , realloc(), free()
// Author : Eshita Das
//  gcc dmalloctn.c -o d
//  .\d.exe
int main()
{

    /*
      //malloc() function
        int* ptr;
        int n;
        printf("Enter the size of the array you want to create \n");
        scanf("%d",&n);
        ptr = (int*) malloc(n*sizeof(int));
        for(int i=0; i<n;i++){
         printf("Enter the value at index: %d\n",i);
         scanf("%d",&ptr[i]);
        }
        for(int i=0; i<n;i++){
         printf("The value at index %d is : %d\n",i,ptr[i]);
        }
    */

    /*
      //calloc() function
       int* ptr;
       int n;
       printf("Enter the size of the array you want to create \n");
       scanf("%d",&n);
       ptr = (int*) calloc(n,sizeof(int));
       for(int i=0; i<n;i++){
        printf("Enter the value at index: %d\n",i);
        scanf("%d",&ptr[i]);
       }
       for(int i=0; i<n;i++){
        printf("The value at index %d is : %d\n",i,ptr[i]);
       }
    */


    // realloc() function
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create \n");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    // ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value at index: %d\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value (previous value) at index %d is : %d\n", i, ptr[i]);
    }
    printf("Enter the size of the array you want to create \n");
    scanf("%d", &n);
    ptr = (int *)realloc(ptr, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value at index: %d\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value (new value) at index %d is : %d\n", i, ptr[i]);
    }

    free(ptr);
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("The value (new value after free) at index %d is : %d\n", i, ptr[i]);
    }

/*

    Enter the size of the array you want to create
    2
    Enter the value at index: 0
    12
    Enter the value at index: 1
    23
    The value (previous value) at index 0 is : 12
    The value (previous value) at index 1 is : 23
    Enter the size of the array you want to create
    5
    Enter the value at index: 0
    12
    Enter the value at index: 1
    23
    Enter the value at index: 2
    45
    Enter the value at index: 3
    56
    Enter the value at index: 4
    67
    The value (new value) at index 0 is : 12
    The value (new value) at index 1 is : 23
    The value (new value) at index 2 is : 45
    The value (new value) at index 3 is : 56
    The value (new value) at index 4 is : 67


    The value (new value after free) at index 0 is : 11998840
    The value (new value after free) at index 1 is : 11993280
    The value (new value after free) at index 2 is : 45
    The value (new value after free) at index 3 is : 56
    The value (new value after free) at index 4 is : 67



*/


    return 0;
}