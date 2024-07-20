#include <stdio.h>
// gcc searchArr.c -o a
//.\a.exe

void main()
{
    int arr[30];
    int size, search, option, found = 0;
    printf("Enter the size of the array you want : ");
    scanf("%d", &size);
    printf("Now enter the array values \n");
    int i = 0;

    while (i < size)
    {
        printf("Enter the value at %d = ", i);
        scanf("%d", &arr[i]);
        i++;
    }

    printf("Now enter an option you want to perform : \n1. search for a value in the array , \n2. print all the elements of the array \n");
    scanf("%d", &option);

    if (option == 1)
    {
        printf("Now enter a value to search for :");
        scanf("%d", &search);

        i = 0;
        while (i < size)
        {
            found = 0;
            if (arr[i] == search)
            {
                printf("%d is present at index=%d in the array\n", search, i);
                found = 1;
                break;
            }
            i++;
        }

        if (found == 0)
        {
            printf("%d doesn't exist in the array\n", search);
        }
    }
    else if (option == 2)
    {
        i = 0;
        printf("Printing all the elements in the aray \n");
        while (i < size)
        {
            printf(" %d ", arr[i]);
            i++;
        }
    }
}