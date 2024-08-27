#include <stdio.h>
#include <stdlib.h>
// gcc io.c -o a
//.\a.exe
void main()
{
    int arr[30];
    int size, num, pos, op;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("Enter value at position %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nNow printing the array : \n");
    for (i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    while (1)
    {
        printf("\nEnter an option you want to perform :\n1. Enter an element at starting position, \n2. Enter an element at a specific position, \n3. Enter an element at the end of the array. \n4. to exit. ");
        printf("\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nEnter the number you want to insert : ");
            scanf("%d", &num);
            // insertion at starting
            for (i = size - 1; i >= 0; i--)
            {
                arr[i + 1] = arr[i];
            }
            size++;
            arr[0] = num;
            break;
        case 2:
            printf("\nEnter the number you want to insert : ");
            scanf("%d", &num);
            // insertion at a specific position
            printf("Enter the position where you want to insert :");
            scanf("%d", &pos);

            if (pos > 0)
            {

                for (i = size - 1; i >= pos - 1; i--)
                {
                    arr[i + 1] = arr[i];
                }
                size++;
                arr[pos - 1] = num;
            }
            else
            {
                printf("Invalid position\n");
            }
            break;
        case 3:
            printf("\nEnter the number you want to insert : ");
            scanf("%d", &num);
            // insertion at end
            size++;
            arr[size - 1] = num;
            break;

        case 4:
            // to exit programme
            exit(0);
            break;
        default:
            printf("Invalid option!");
        }

        printf("\nNow printing the array : \n");
        for (i = 0; i < size; i++)
        {
            printf(" %d ", arr[i]);
        }
    }
}