#include <stdio.h>
#include <stdlib.h>
#define MAX 50
// gcc insert.c -o a
void printArr(int a[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf(" %d ",a[i]);
    }
}

int main()
{
    int a[MAX];
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);

    printf("\nNow enter the values in the array\n");
    for(int i=0;i<size;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    printf("\nNow printing the array\n");
    printArr(a,size);

    int op,num,i,pos;

    while(1)
    {   
        printf("\nSelect an option to insert an element in the array :\n");
        printf("1.Insert at the beginning ,\n2.Insert at a specific position,\n3.Insert at the end\n4. Exit \n Select : ");
        scanf("%d",&op);

       // 1,2,3,4
        switch (op)
        {
        case 1:
            printf("\nEnter a number to insert : ");
            scanf("%d", &num);
            for(i=size-1;i>=0;i--)
            {
               a[i+1]=a[i];
            }
            a[0]=num;
            size++;
           
            break;
        case 2:
            printf("\nEnter a number to insert : ");
            scanf("%d", &num);
            printf("\nNow enter the position where you want to insert : ");
            scanf("%d",&pos);
            for(i=size-1;i>=pos-1;i--)
            {
                a[i+1]=a[i];
            }
            a[pos-1] = num;
            size++;

            break;
        case 3:
            printf("\nEnter a number to insert : ");
            scanf("%d", &num);
            a[size]=num;
            size++;
           
            break;
        case 4:
            exit(0);
            break;
        
        default:
           printf("Invalid option.\n");
            break;
        }

        printf("\nNow printing the array\n");
        printArr(a, size);
    }


    return 0;
}