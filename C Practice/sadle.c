#include <stdio.h>


void main()
{
  int a[10][10];
  int r,c,i,j,k,min,col,max,flag=0;
  printf("Enter the max. no. of rows: ");
  scanf("%d",&r);

  printf("Enter the max no. of cols: ");
  scanf("%d",&c);
  
  for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
      {
       printf("a[%d][%d] = ",i,j);
       scanf("%d",&a[i][j]);
      }
  }


  printf("\nNow printing the matrix...\n");
   for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
      {
       printf(" %d ",a[i][j]);
      }
      printf("\n");
  }

 
  //find the sadle point of a matrix || sadle point : minimum in the row and maximum in the column
  for(i=0;i<r;i++)
   {
     
     for(j=0;j<c;j++)
     {
        min = a[i][0];
        col=0;
       if(a[i][j]<min)
         {
           min = a[i][j];
           col = j;
         }
     }
     max =0;
     for(k=0;k<r;k++)
     {
       if(a[k][col]>max)
        {
          max = a[k][col];
        }
     }
    
     if(min==max)
     {
       printf("Saddle point of the matrix is = %d",max);
       flag = 1;
       break;
     }
     
   }

   if(flag==0)
   {
     printf("Saddle point not found");
   }
}