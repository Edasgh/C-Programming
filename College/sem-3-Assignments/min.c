#include <stdio.h>

void printM(int a[10][10], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
}

void row_Min(int a[10][10],int r ,int c)
{
    int i=0,j=0,minR;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
          minR = a[i][0];
       
          if(a[i][j]<minR)
          {
            minR = a[i][j];
           
          }
        }
     printf("minimum in row %d is %d\n",i+1,minR);
    

    }
}


void col_Min(int a[10][10], int r, int c)
{
    int i=0,j=0,minC;
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            minC = a[0][i];
           if(a[j][i]<minC)
           {
            minC = a[j][i];
           }
        }
        printf("minimum in column %d is %d\n", i+1, minC);
    }
}



void main()
{
    int arr[10][10];
    int rows, cols;
    printf("Enter the max. no. of rows : ");
    scanf("%d", &rows);
    printf("Enter the max. no. of columns : ");
    scanf("%d", &cols);
    printf("\nNow enter all the values :\n");
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    printf("Now printing the matrix:\n");
    printM(arr, rows, cols);
    printf("\n");
    row_Min(arr,rows,cols);
    col_Min(arr,rows,cols);
   
}