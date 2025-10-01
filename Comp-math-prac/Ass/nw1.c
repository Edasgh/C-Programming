#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
    //x^3-8x-4
    return powf(x,3)-(8*x)-4;
}
float fd(float x){
    // 3x^2-8
    return (3*x*x)-8;
}

float evaluateNewtonRaphson(float a,float b,float error){
  
    float x1,x,h;
    x=fabsf(f(a))<fabsf(f(b))?a:b;
    x1=x;
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
    //get initial values of a & b
    while(f(a)*f(b)>0){
        a+=0.5;
        b+=0.5;
    }

    int acc;
    printf("Enter the accuracy (upto a decimal place) : ");
    float err = 1;
    for (int i = 0; i <= acc; i++)
    {
        err /= 10;
    }

    float result = evaluateNewtonRaphson(a,b,err);
    printf("The root of x^3-8x-4=0 by using Newton Raphson method is %f\n",result);

    return 0;
}