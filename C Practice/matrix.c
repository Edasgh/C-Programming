#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 50
#define MAX_COLS 50

// gcc matrix.c -o a

void printM(int a[MAX_ROWS][MAX_COLS],int r1,int c1)
{
    int i=0,j=0;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf(" %d ",a[i][j]);
        }
        printf("\n");
    }
}

void multM(int a[MAX_ROWS][MAX_COLS], int b[MAX_ROWS][MAX_COLS],int r1, int r2, int c1, int c2)
{
 int result[MAX_ROWS][MAX_COLS];
 int i=0,j=0,k=0;
 if(c1==r2)
 {
  

  for(i=0;i<r1;i++)
  {
    for(j=0;j<c2;j++)
    {
        result[i][j]=0;

        for(k=0;k<r2;k++)
        {
            result[i][j]+=a[i][k]*b[k][j];
        }
    }
  }
  printf("Printing the product matrix : \n");
  printM(result,r1,c2);
  
 }
 else
 {
    printf("Multiplication not possible");
 }

}

void main()
{
  int a[MAX_ROWS][MAX_COLS];
  int b[MAX_ROWS][MAX_COLS];
  int r1,r2,c1,c2;
  printf("For the first matrix\n");
  printf("Enter the max. no. of rows : ");
  scanf("%d",&r1);
  printf("\nEnter the max. no. of columns : ");
  scanf("%d",&c1);
  printf("Now enter the values :\n");
  int i=0,j=0;
  for(i=0;i<r1;i++)
  {
    for(j=0;j<c1;j++)
    {
        printf("a[%d][%d] = ",i,j);
        scanf("%d",&a[i][j]);
    }
  }
  printf("Printing the first matrix : \n");
  printM(a,r1,c1);
  printf("For the second matrix\n");
  printf("Enter the max. no. of rows : ");
  scanf("%d",&r2);
  printf("\nEnter the max. no. of columns : ");
  scanf("%d",&c2);
  printf("Now enter the values :\n");
  for (i = 0; i < r2; i++)
  {
      for (j = 0; j < c2; j++)
      {
          printf("b[%d][%d] = ",i,j);
          scanf("%d", &b[i][j]);
      }
  }
  printf("Printing the second matrix : \n");
  printM(b, r2, c2);

  multM(a,b,r1,r2,c1,c2);

 

}