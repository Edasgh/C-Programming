#include <stdio.h>
#include <stdlib.h>

float f(float x){
    return (4 * x) - (3 * x * x);
}

float evaluateSimpsonsRule(float u,float l,int n){
    float h = (u-l)/n;
    float x =l;
    float y=0;
    int i=0;
    while(i<=n){
        printf("Iteration = %d, x=%f, y=%f \n",i,x,f(x));
        if(i==0||i==n){
            y+=f(x);
        }else if(i%2==0){
            y+= (2*f(x));
        }else if(i%2!=0){
            y+=(4*f(x));
        }
        i++;
        x+=h;
    }
    y*=(h/3);
    return y;
}

void main(){
    printf("Integrating (4x-3x^2) using Simpson's 1/3rd rule \n");
    float u,l;
    printf("Enter the lower limit : ");
    scanf("%f",&l);
    printf("Enter the upper limit : ");
    scanf("%f",&u);

    int n;
    printf("Enter the no. of intervals : ");
    scanf("%d",&n);
    if(n%2!=0){
        printf("Simpsons rule can only be applied on even intervals : ");
        exit(0);
    }

    float result = evaluateSimpsonsRule(u,l,n);
    printf("The result of integrating (4x-3x^2) from lower limit %f to upper limit %f using Simpsons 1/3rd rule is :\n%f",l,u,result);

}