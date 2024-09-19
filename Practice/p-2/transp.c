#include <stdio.h>


void main()
{
  int a[10][10], r, c;
  printf("Enter the max. no. of rows: ");
  scanf("%d",&r);
  printf("Enter the max. no. of columns: ");
  scanf("%d",&c);

  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
     {
       printf("a[%d][%d] = ",i,j);
       scanf("%d",&a[i][j]);
     }
  }

  printf("Now printing the matrix \n");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
     {
       printf(" %d ",a[i][j]);
     }
     printf("\n");
  }
  //second method
  int ta[10][10];
  
  for(i=0;i<c;i++)
  {
    for(j=0;j<r;j++)
     {
       ta[i][j]=a[j][i];
     }
   
  }

   printf("Now printing the transpose matrix \n");
  for(i=0;i<c;i++)
  {
    for(j=0;j<r;j++)
     {
       printf(" %d ",ta[i][j]);
     }
     printf("\n");
  }
}