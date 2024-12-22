#include <stdio.h>

void main()
{
    int row, col;
    int a[20][20];

    printf("Enter the max. no. of rows : ");
    scanf("%d", &row);
    printf("Enter the max. no. of cols : ");
    scanf("%d", &col);

    int i = 0, j = 0;
    printf("Now enter all the values :\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {

            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }

    int total = row * col;
    int count = 0;

    printf("The non-zero values in the matrix :\nRow\t  Col\t  Val\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (a[i][j] != 0)
            {
                count++;
                printf("%d\t  %d\t  %d\n", i, j, a[i][j]);
            }
        }
    }


    	if(count>=total/3)
    	{
    		printf("\nThe matrix is a sparse matrix");
    	}
    	else
    	{
    		printf("\nThe matrix is not a sparse matrix");
    	}
}