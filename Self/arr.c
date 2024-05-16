#include <stdio.h>
// gcc arr.c -o arr
void main()
{
    // int marks[4]={4,53,29,45}; // initialization with decalration // 1d array
    // marks[0]=75;
    // marks[2]=90;
    // marks[3]=80;
    // printf("The marks obtained by student 3 is %d\n",marks[2]);
    // marks[2]=79;
    // printf("The marks obtained by student 3 is %d\n",marks[2]);

    // for(int i=0;i<4;i++)
    // {
    //     printf("Enter the value of %dth element of the array\n",i);
    //     scanf("%d",&marks[i]);
    // }
    // for(int i=0;i<4;i++)
    // {
    //     printf("The value of %dth element of the array is %d\n",i,marks[i]);

    // }

    // 2d array
    int marks[2][4] = {{45, 68, 89, 90}, {89, 88, 45, 60}}; // 2-rows, 4-columns
    for (int i = 0; i < 2; i++) // now the array will be prnted as a matrix
    {
        for (int j = 0; j < 4; j++)
        {
            // printf("The value of element of the %dth row and %dth column of the array is %d\n", i, j, marks[i][j]);
            printf("%d ",marks[i][j]);
        }
        printf("\n");
    }
}