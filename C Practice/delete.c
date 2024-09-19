#include <stdio.h>
#include <stdlib.h>
#define MAX 50

//gcc delete.c -o a

void printArr(int a[],int size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        printf(" %d ",a[i]);
    }
}
void main()
{
    int a[MAX];
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
   int i,op,pos;
   printf("\nNow enter the elements in the array :\n");
   for(i=0;i<size;i++)
   {
    printf("a[%d] = ",i);
    scanf("%d",&a[i]);
   }

    while(1)
    {
        printf("\nSelect an option to delete an element from the array :\n");
        printf("1.Delete from the beginning ,\n2.Delete from a specific position,\n3.Delete from the end\n4. Exit \n Select : ");
        scanf("%d", &op);

        switch(op)
        {
            // 1 2 3 4 5
            case 1:
            for(i=0;i<size;i++)
            {
                a[i]=a[i+1];
            }
            size --;
            break;
            case 2:
            printf("\nEnter the position from where you want to delete : ");
            scanf("%d",&pos);
            for(i=pos-1;i<size-1;i++)
            {
                a[i]=a[i+1];
            }
            size--;
            break;
            case 3:
            size--;
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nInvalid Option.");

        }

        printf("\nNow printing the array\n");
        printArr(a, size);
    }
}