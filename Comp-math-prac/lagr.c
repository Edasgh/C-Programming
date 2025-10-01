#include <stdio.h>
#include <math.h>
// the lagrange's interpolation method


void main(){
    int n;
    printf("Enter the total no. of data : ");
    scanf("%d",&n);
    float x[n];
    float y[n];
    printf("Enter the x values : \n");
    for(int i=0;i<n;i++){
        printf(" x%d = ",i);
        scanf("%f",&x[i]);
    }
    printf("Enter the y values : \n");
    for (int i = 0; i < n; i++)
    {
        printf(" y%d = ", i);
        scanf("%f", &y[i]);
    }
    float x1;
    printf("Enter the number to find f(x) :  ");
    scanf("%f",&x1);
    float res=0;

    for(int i=0;i<n;i++){
      float term1=1,term2=1;
      for(int j=0;j<n;j++){
        if(i!=j){
            term1*=(x1-x[j]);
        }
      }
       term1*=y[i];
      for(int k=0;k<n;k++){
        if(i!=k){
          term2*= (x[i]-x[k]);
        }
      }
      res+=(term1/term2);
    }

    printf("The result of f(%.f) is : %.f ",x1,res);

}