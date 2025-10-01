#include <stdio.h>
#include <stdlib.h>

float f(float x){
    return (4*x)-(3*x*x);
}

float evaluateTZ(float u,float l,int n){
    float h = (u-l)/n;
    float x=l,y,result=0;
    int i=0;
    while(i<=n){
       y=f(x);
       printf("Iteration %d, x=%f, y=%f\n",i,x,y);
       if(i==0||i==n){
        result+=y;
       }else if(i%2==0){
        result+=(2*y);
       }else{
        result+=(4*y);
       }
       x+=h;

        i++;
    }
    result*=(h/3);
    return result;
}

void main(){
    printf("Integrating 4x-3x^2 with respect to x using Trapezoidal's rule :\n");
    float l,u;
    printf("Enter the lower limit : ");
    scanf("%f",&l);
    printf("Enter the upper limit : ");
    scanf("%f",&u);

    int n;
    printf("Enter the no. of intervals : ");
    scanf("%d",&n);

    float result = evaluateTZ(u,l,n);
    printf("Integrating 4x-3x^2 from lower limit %f to upper limit %f via Trapezoidal's rule we get: %f\n",l,u,result);

}