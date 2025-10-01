#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// y = a0 + a1 * x + a2 * x^2;

// 3
// sum_y = n * a0 + sum_x * a1 + sum_x_2 * a2;
// sum_xy = a0 * sum_x + a1 * sum_x_2 + a2 * sum_x_3;
// sum_x_2_y = a0 * sum_x^2 + a1 * sum_x_3 + a2 * sum_x_4

void main(){
    int n;
    printf("Enter the no. of points : ");
    scanf("%d",&n);

    float aug[3][4],x[n],y[n],a[3];

    printf("Enter the points : \n");
    for(int i=0;i<n;i++){
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
        printf("y[%d] = ",i);
        scanf("%f",&y[i]);
        printf("(x[%d],y[%d]) = (%f,%f)\n",i,i,x[i],y[i]);
    }

    float sum_x=0,sum_y=0,sum_xy=0,sum_x_2=0,sum_x_3=0,sum_x_4=0,sum_x_2_y=0;
    for(int i=0;i<n;i++){
      sum_x+=x[i];
      sum_x_2+=(x[i]*x[i]);
      sum_x_3+=(x[i]*x[i]*x[i]);
      sum_x_4+=(x[i]*x[i]*x[i]*x[i]);
      sum_y+=y[i];
      sum_xy+=(x[i]*y[i]);
      sum_x_2_y+=(x[i]*x[i]*y[i]);

    }

    // build the augmented matrix
    //  n * a0 + sum_x * a1 + sum_x_2 * a2 = sum_y
    //  a0 * sum_x + a1 * sum_x_2 + a2 * sum_x_3 = sum_xy
    //  a0 * sum_x^2 + a1 * sum_x_3 + a2 * sum_x_4 = sum_x_2_y
    // 1st row
    aug[0][0] = n;
    aug[0][1] = sum_x;
    aug[0][2] = sum_x_2;
    aug[0][3] = sum_y;

    // 2nd row
    aug[1][0] = sum_x;
    aug[1][1] = sum_x_2;
    aug[1][2] = sum_x_3;
    aug[1][3] = sum_xy;

    // 3rd row
    aug[2][0] = sum_x_2;
    aug[2][1] = sum_x_3;
    aug[2][2] = sum_x_4;
    aug[2][3] = sum_x_2_y;

    printf("\nPrinting the augmented matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f ", aug[i][j]);
        }
        printf("\n");
    }

   // upper triangular matrix
   for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(j>i){
            float m = aug[j][i]/aug[i][i];
            for(int k=0;k<4;k++){
                aug[j][k]-=(m*aug[i][k]);
            }
        }
    }
   }

   printf("\nPrinting the upper triangular matrix\n");
   for (int i = 0; i < 3; i++)
   {
       for (int j = 0; j < 4; j++)
       {
           printf("%f ", aug[i][j]);
       }
       printf("\n");
   }

   // back substituition
   a[2]=aug[2][3]/aug[2][2];
   for(int i=3-2;i>=0;i--){
    float sum=0;
    for(int j=i+1;j<3;j++){
        sum+=aug[i][j]*a[j];
    }
    a[i]=(aug[i][n]-sum)/aug[i][i];
   }

   //print the equation
   printf("The best fit parabola for the given points is: y=(%f)+(%f)x+(%f)x^2\n",a[0],a[1],a[2]);
}