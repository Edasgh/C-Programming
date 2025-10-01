#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float f(float x){
    return (x*x)+(2*x)-2;
}

float fd(float x){
    return (2*x)+2;
}

float evaluateNewtonRaphson(float x,float error){
    float x1=x;
    float h;
    while(1){
        h=f(x1)/fd(x1);
        x1=x1-h;

        if(fabsf(x1-x)<error){
            return x1;
        }
        x=x1;

    }
}

int main(){
    float a=0,b=0.5;
    while(f(a)*f(b)>0){
        a+=0.5;
        b+=0.5;
    }

    float x = fabsf(f(a))<fabsf(f(b))?a:b;

    int acc;
    printf("Enter the accuracy ( in decimal places ) : ");
    scanf("%d",&acc);
    float err=1;
    for(int i=0;i<acc;i++){
        err/=10;
    }

    float result = evaluateNewtonRaphson(x,err);
    printf("The root of the equeation : x^2+2x-2=0 via Newton Raphson method is : %f\n",result);
    
    return 0;
}