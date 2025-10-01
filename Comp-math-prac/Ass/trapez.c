#include <stdio.h>
#include <stdlib.h>

float f(float x){
    float r=1/(1+x);
    return r;
}

float evaluateTrapezoidal(float a,float b,float n){
    float h = (b-a)/n;
    float sum=0;
    int i=0;
    while(i<=n){
        if(i==0||i==n){
            sum+=f(a);
        }else{
            sum+=(2*f(a));
        }
        i++;
        a+=h;
    }
    sum=sum*(h/2);
    return sum;
}

void main(){
    printf("-----Integration of 1/(1+x) using Trapeoidal rule-----\n");
    float a=0,b=5;
    int n;
    printf("Enter the no. of intervals : ");
    scanf("%d",&n);

    float result = evaluateTrapezoidal(a,b,n);
    printf("The result of integrating 1/(1+x) from 0 to 5 with %d intervals is %f\n",n,result);


}