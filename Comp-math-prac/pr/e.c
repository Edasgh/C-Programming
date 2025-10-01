#include <stdio.h>
#include <stdlib.h>

float df(float x,float y){
    return (x+2*y);
}
// x = x + h
// y = y + h*df(x,y)
// repeat untill x-val < 0.001

float evaluateEm(float x,float y,float h,float val){
    float x1=x,y1=y;
    while(1){
        if(fabs(x1-val)<0.001){
            return y1;
        }
        x1=x1+h;
        y1=y1+h*df(x1,y1);
    }

}

void main(int argc,char *argv[]){
    printf("Implementing Euler's method on x+2y=0\n");
    float x,y,h,val;
    printf("Enter the initial x value : ");
    scanf("%f",&x);
    printf("Enter the initial value of y : ");
    scanf("%f",&y);

    printf("Enter the value of h : ");
    scanf("%f",&h);

    printf("Enter the x to find y : ");
    scanf("%f",&val);

    float result = evaluateEm(x,y,h,val);
    printf("f(%f) = %f\n",val,result);
}
