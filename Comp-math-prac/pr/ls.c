#include <stdio.h>
#include <stdlib.h>

// linear curve fitting
// sum_y = n * a0 + a1 * sum_x
// sum_xy = sum_ * a0 + a1 * sum_x^2

void main(){
    int n;
    printf("Enter the length of data : ");
    scanf("%d",&n);

    float aug_m[2][3],x[n],y[n],a[2];
    printf("Enter the points : \n");
    for(int i=0;i<n;i++){
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
        printf("y[%d] = ",i);
        scanf("%f",&y[i]);
        printf("(x%d,y%d)= (%f,%f)\n",i,i,x[i],y[i]);
    }

    //sum_x
    float sum_x=0;
    for(int i=0;i<n;i++){
        sum_x+=x[i];
    }
    //sum_x^2
    float sum_x_2=0;
    for (int i = 0; i < n; i++)
    {
        sum_x_2 += (x[i]*x[i]);
    }
    //sum_y
    float sum_y=0;
    for(int i=0;i<n;i++){
        sum_y+=y[i];
    }
    //sum_xy
    float sum_xy=0;
    for(int i=0;i<n;i++){
        sum_xy+=(x[i]*y[i]);
    }

    // build the augmented matrix
    //  linear curve fitting
    // sum_y = m * sum_x + n*c
    // sum_xy = m * sum_x^2+sum_x * c
    aug_m[0][0]=sum_y;
    aug_m[0][1]=n;
    aug_m[0][2]=sum_x;
    aug_m[1][0]=sum_xy;
    aug_m[1][1]=sum_x;
    aug_m[1][2]=sum_x_2;
    printf("The augmented matrix : \n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%f ",aug_m[i][j]);
        }
        printf("\n");
    }

    //build the upper triangular matrix
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        if(j>i){
            float m = aug_m[j][i] / aug_m[i][i];
            for(int k=0;k<3;k++){
                aug_m[j][k]-=(m*aug_m[i][k]);
            }

        }
      }
    }
    printf("Printing the upper triangular matrix : \n");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%f ",aug_m[i][j]);
        }
        printf("\n");
    }

    // apply back substituition
    a[1]=aug_m[1][2]/aug_m[1][1];
    a[0] = (aug_m[0][2]-(aug_m[0][1]*a[1]))/aug_m[0][0];
    printf("The line to fit the given data is : y=(%f)x+(%f)\n",a[0],a[1]);

}