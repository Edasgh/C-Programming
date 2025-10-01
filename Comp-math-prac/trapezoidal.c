#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x){
    // 1/x
    float result = 1/x;
    return result;

}


float evaluateTrapezoidal(int n,float a,float b){
    float h = (b-a)/n;
    float res = 0 ;
    float x = a;
    int i=0;
    while(i<=n){
        if(i==0||i==n){
             res+=f(x);
        }else{
           res+=(2*f(x));
        }
        x+=h;
        i++;
    }
    res*=h/2;
   

    return res;
}

void main(){
    printf("Integration using trapezoidal's rule : \n");    
    int n;
    printf("Enter the no. of intervals : ");
    scanf("%d",&n);
    if(n%2==0){
        printf("Trapezoidal can't be applied on even intervals");
        exit(0);
    }
    float a,b;
    printf("Enter the lower limit of integral : ");
    scanf("%f",&a);
    printf("Enter the upper limit of integral : ");
    scanf("%f", &b);

    float result = evaluateTrapezoidal(n,a,b);
    printf("The result of integration of 1/x from %.2f to %.2f with %d intervals is : %.4f\n",a,b,n,result);
   
}