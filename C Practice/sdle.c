#include <stdio.h>


int main()
{
    /*
    int a [50][50];
    int r,c;
    printf("Enter the max. no. of rows : ");
    scanf("%d",&r);
    printf("\nEnter the max. no. of columns : ");
    scanf("%d", &c);
    printf("Now enter the values : \n");
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nNow printing the matrix :\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" %d ",a[i][j]);

        }
        printf("\n");
    }

    int min=0,max=0,col;
    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
        min = a[i][0];
        col =0;
            if(a[i][j]<min)
            {
              min = a[i][j];
              col = j;
            }
        }
        for(j=0;j<r;j++)
        {
            if(a[j][col]>max)
            {
                max = a[j][col];
            }
        }
    }

    if(min==max)
    {
        printf("The saddle point of the matrix is : %d\n",max);
    }
    else
    {
        printf("The matrix has no saddle point\n");
    }
    */

   //transpose

   int a[40][40];
   int r,c;
   printf("Enter the no. of max. rows : ");
   scanf("%d",&r);
   printf("\nEnter the no. of max. columns : ");
   scanf("%d", &c);

  printf("\nNow enter the elements of the matrix :\n");
   int i,j;
   for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
    {
        printf("a[%d][%d] = ",i,j);
        scanf("%d",&a[i][j]);
    }
   }

   //print
   printf("\nNow printing the matrix : \n");
   for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
    {
        printf(" %d ",a[i][j]);
    }
    printf("\n");
   }
   //transpose
    int b[50][50];

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            b[i][j] = a[j][i];
        }
    }
   //print
    printf("\nNow printing the transpose matrix : \n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf(" %d ", b[i][j]);
        }
        printf("\n");
    }

   return 0;
}