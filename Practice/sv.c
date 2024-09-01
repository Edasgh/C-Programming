#include <stdio.h>

void main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int a[size];
    int odds[100];
    int evens[100];
    int oddIdx=0,evIdx=0;
    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Now printing the array : ");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }

    for (int i = 0; i < size; i++)
    {
        
       if(a[i]%2==0)
       {
        evens[evIdx]=a[i];
        evIdx++;
       }
       else
       {
        odds[oddIdx]=a[i];
        oddIdx++;
       }
    }

    printf("\nNow printing the even array : ");
    for (int i = 0; i <evIdx; i++)
    {
        printf(" %d ", evens[i]);
    }
    printf("\nNow printing the odd array : ");
    for (int i = 0; i <oddIdx; i++)
    {
        printf(" %d ", odds[i]);
    }
}