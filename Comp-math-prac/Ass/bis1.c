#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//bisection method
// problem - 1

float f(float x){
    float r = (x*x*x)-(9*x)+1;
    return r;
}

float evaluateBisection(float a, float b,float error){

      float x1;
      while(1){
        x1=(a+b)/2;
        if(f(x1)>0){
            if(fabsf(b-x1)<error){
                return b;
            }
            b=x1;
        }else{
            if (fabsf(a - x1) < error)
            {
                return a;
            }
            a = x1;
        }
      }

}

int main(int argc,char *argv[]){
    
    float a=0,b=0.5;
    while(f(a)*f(b)>0){
       a+=0.5;
       b+=0.5;
    }

    int acc;
    printf("Enter the accuracy (upto a decimal place) : ");
    scanf("%d",&acc);
    float err=1;
    for(int i=0;i<=acc;i++){
        err/=10;
    }

    float result = evaluateBisection(a,b,err);
    printf("The root of x^3-9x+1=0 via bisection method is %f\n",result);

    return 0;
}