#include <stdio.h>
#include <stdlib.h>

float f(float x){
    return (4*x - 3*x*x);
}

float evaluateSimpsons(float a,float b,float n){
    float h = (b-a)/n;
    float x=a;
    float y=f(x);
    float sum=0;
    int i=0;
    while(i<=n){
    
        if(i==0||i==n){
            sum+=y;
        }else if(i%2==0){
            sum+=2*y;
        }else if(i%2!=0){
            sum+=4*y;
        }
        i++;
        x += h;
        y = f(x);
    }

    return sum*(h/3);
}

void main(){
    printf("------Integration of (4x-3x^2) using Simpson's rule------\n");
    int n;
    printf("Enter the no. of intervals (even number) : ");
    scanf("%d",&n);
    if(n%2!=0){
        printf("Intervals in simpsons rule can't be an odd number ");
        exit(0);
    }

    float a=0,b=1;

    float result = evaluateSimpsons(a,b,n);
    printf("The result of integrating (4x-3x^2) from 0 to 1 is : %f\n",result);


}