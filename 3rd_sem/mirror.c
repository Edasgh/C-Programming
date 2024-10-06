#include <stdio.h>
// mirror matrix
void printM(int m[10][10],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf(" %d ",m[i][j]);
        }
        printf("\n");
    }
}

void mirror(int m[10][10],int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
       for(j=c-1;j>=0;j--)
       {
        printf("%d ",m[i][j]);
       }
       printf("\n");
    }
}

void main()
{
    int matrix[10][10];
    int rows,cols;
    printf("Enter the max. no. of rows : ");
    scanf("%d",&rows);
    printf("Enter the max. no. of columns : ");
    scanf("%d",&cols);
    printf("\nNow enter all the values :\n");
    int i,j;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
              scanf("%d",&matrix[i][j]);
        }
        printf("\n");
    }

    printf("Now printing the matrix:\n");
    printM(matrix,rows,cols);
    printf("\nNow printing the matrix in mirror pattern :\n");
   mirror(matrix,rows,cols);

}