#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float fd(float x,float y){
    return (x + 2*y);
}

float evaluateEulersMethod(float h,float y,float x,float val){
    float y1 = y;
    float x1 = x;
    x1=x1+h;
    y1=y1+h*fd(x1,y1);
    while(1){
        if(fabsf(x1-val)<0.001)
        break;

        x1 = x1 + h;
        y1 = y1 + h * fd(x1,y1);
    }

    return y1;


}

void main(){
  float val,x,y,h;
  printf("Enter the initial value of x : ");
  scanf("%f",&x);
  printf("Enter the initial value of y=f(%f) : ",x);
  scanf("%f", &y);
  printf("Enter the value of h : ");
  scanf("%f",&h);
  printf("Enter the x value to find f(x) : ");
  scanf("%f",&val);

  float result = evaluateEulersMethod(h,y,x,val);
  printf("The result of f(%4.2f) is %4.3f : ",val,result);

}