#include <stdio.h>
#include <stdlib.h>

void takeVal (int a[],int size);
void printVals(int a[],int size);
void insert (int a[],int size);
void delVal(int a[],int size);


void main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int a[size];
    takeVal(a,size);
    printVals(a,size);
    // insert(a,size);
    // delVal(a,size);



}

void delVal(int a[],int size)
{
    int i=0,pos;
    while (1)
    {
        int op;
        printf("\nChoose an action to perform : \n1. Delete an element from the starting of the array , \n2.Delete an element from the end of the array , \n3. Delete an element from a specific position of the array, \n 4. Exit \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
          for(i=0;i<size-1;i++)
          {
            a[i]=a[i+1];
          }
          size--;
          printVals(a, size);
          break;
        case 2:
         size--;
         printVals(a, size);
         break;
        case 3:
            printf("Now enter the position from where you want to delete : ");
            scanf("%d", &pos);
            if (pos == 0 || pos > size)
            {
                printf("Invalid position");
            }
            else
            {
                 for(i=pos-1;i<size-1;i++)
                 {
                    a[i]=a[i+1];
                 }
                 size--;
            }
            printVals(a, size);
            break;
        case 4:
            printVals(a, size);
            exit(0);
            break;
        
        default:
            printf("Invalid option");
        }

    }

    }

void takeVal (int a[],int size)
{
    int i=0;
    printf("\nNow enter all the values\n");
    for(i=0;i<size;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

void printVals (int a[],int size)
{
    int i = 0;
    printf("\nNow printing the array : \n");
    for (i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
      
    }
}

void insert(int a[], int size)
{
    int i=0;
    int val,pos;
    while(1){
    int op;
    printf("\nChoose an action to perform : \n1. Insert at the starting of the array , \n2.Insert at the end of the array , \n3. Insert at a specific position of the array, \n 4. Exit \n");
    scanf("%d",&op);

// {0,8,9,12,23}
    switch(op){
        case 1:
        printf("Enter a number to insert : ");
        scanf("%d",&val);
        for(i=size-1;i>=0;i--)
        {
          a[i+1]=a[i];
        }
        a[0]=val;
        size++;
        printVals(a, size);
        break;
        case 2:
            // {0,8,9,12,23}
            printf("Enter a number to insert : ");
            scanf("%d", &val);
            size++;
            a[size-1]=val;
            printVals(a, size);
            break;
        case 3:
            printf("Enter a number to insert : ");
            scanf("%d", &val);
            printf("Now enter the position where you want to insert : ");
            scanf("%d",&pos);
            if(pos==0 || pos>size)
            {
                printf("Invalid position");
            }
            else
            {
            for(i=size-1;i>=pos-1;i--)
            {
                a[i+1]=a[i];
            }
            a[pos-1]=val;
            size++;
            }
            printVals(a, size);
            break;
        case 4:
            printVals(a, size);
            exit(0);
            break;
        default:
        printf("Invalid option");
        
    }
    }

    

}