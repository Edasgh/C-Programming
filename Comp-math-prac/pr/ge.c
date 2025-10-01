#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    float m, sum;
    int n;
    printf("Enter the no. of unknowns : ");
    scanf("%d", &n);

    float a[n][n + 1],x[n];
    printf("Enter the values in augmented matrix : ");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Printing the augmented matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }

    // upper triangular matrix
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
           if(j>i){
               m = a[j][i] / a[i][i];
               for (int k = 0; k < n + 1; k++)
               {
                   a[j][k] -= (m * a[i][k]);
               }
           }
        }
    }
    printf("The upper triangular matrix : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            printf("%f ",a[i][j]);
        }
        printf("\n");
    }

    //back substituition
    x[n-1] = a[n-1][n]/a[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        sum=0.0;
        for(int j=i+1;j<n;j++){
            sum+=a[i][j]*x[j];
        }
        x[i]=(a[i][n]-sum)/a[i][i];
    }

    printf("\n\nThe required solution\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n\tx%d=%f", i, x[i]); // print the solution
    }
}