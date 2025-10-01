#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//bisection method
// problem - 2

float f(float x){
    return (x * x * x) - x - 1;
}

float evaluateBisection(float a,float b,float error){
    float x1;
    while(1){
        x1=(a+b)/2;
        if(f(x1)<0){
             if(fabsf(x1-a)<error){
                return x1;
             }
             a=x1;
        }else{
            if (fabsf(x1 - b) < error)
            {
                return x1;
            }
            b = x1;
        }
    }
}

void main(){
    float a=0,b=0.5;
    while(f(a)*f(b)>0){
        a+=0.5;
        b+=0.5;
    }

    float err;
    printf("Enter the error tolerance : ");
    scanf("%f",&err);
    err=fabs(err);
    
    float result = evaluateBisection(a,b,err);
    printf("The root of x^3-9x+1=0 via bisection method is %f\n", result);
}