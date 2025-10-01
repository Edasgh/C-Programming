#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
    //x^3-8x-4
    return powf(x,3)-(8*x)-4;
}

float df(float x){
    //3x^2-8
    return (3*powf(x,2))-8;
}

float evaluateNR(float x,float error){
    float h,xn;
    int i=0;
    do{
        printf("Iteration : %d, x=%f, f(x)=%f\n",i,x,f(x));
        h= - f(x)/df(x);
        xn=x+h;
        printf("h=%f, xn=%f, f(xn)=%f\n",h,xn,f(xn));
        x=xn;
        i++;

    }while(fabs(h)>error);
    return xn;
  // x f(x) h xn f(xn)
  // h = - f(x)/df(x)
  // xn=x+h
  // repeat untill h > error
}



void main(){
    float a=0,b=0.5,x;
    while(1){
        if(f(a)*f(b)<0){
            printf("The initial values are : a=%f, b=%f\n",a,b);
            break;
        }
        a+=0.5;
        b+=0.5;
    }

    x=fabs(f(a))<fabs(f(b))?a:b;
    float error;
    printf("Enter the error tolerance : ");
    scanf("%f",&error);
    error=fabs(error);

    float root=evaluateNR(x,error);
    printf("Root = %f\n",root);


}