#include <stdio.h>
#include <stdlib.h>
// Author : Eshita Das
//  gcc dmallctn.c -o de
//  .\de.exe
int main()
{
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create \n");
    scanf("%d", &n);
    // ptr = (int *)calloc(n, sizeof(int));
    ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value at index: %d\n", i);
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("The value (previous value) at index %d is : %d\n", i, ptr[i]);
    }
    free(ptr);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("The value (value after free) at index %d is : %d\n", i, ptr[i]);
    }

    /*
    
    Enter the size of the array you want to create
    4
    Enter the value at index: 0
    1
    Enter the value at index: 1
    2
    Enter the value at index: 2
    3
    Enter the value at index: 3
    4
    The value (previous value) at index 0 is : 1
    The value (previous value) at index 1 is : 2
    The value (previous value) at index 2 is : 3
    The value (previous value) at index 3 is : 4

    The value (value after free) at index 0 is : 11343480
    The value (value after free) at index 1 is : 11337920
    The value (value after free) at index 2 is : 3
    The value (value after free) at index 3 is : 4

    */

    return 0;
}