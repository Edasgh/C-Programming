#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a(-ve) b(+ve) f(a) f(b) xmid f(xmid)
// repeat until fabs(a-b) < error

float f(float x){
    return (x*x*x)-x-1;
}

float evaluateB(float a,float b,float error){
    float xmid;
    int i=0;
    do{
       xmid=(a+b)/2;
       printf("Iteration : %d, a=%f, b=%f, xmid=%f, f(xmid)=%f\n",i,a,b,xmid,f(xmid));
       if(f(xmid)>0){
        b=xmid;
       }else{
        a=xmid;
       }
       if(fabs(a-b)<error){
        return a;
       }
       i++;

    }while(fabs(a-b)>error);

}

void main(){
    float a=0,b=0.5;
    while(1){
        if(f(a)*f(b)<0){
            break;
        }
        a+=0.5;
        b+=0.5;
    }

    printf("The initial values are , a=%f, b=%f\n",a,b);
    float error;
    printf("Enter the error tolerance : ");
    scanf("%f",&error);
    error=fabs(error);

    float result=evaluateB(a,b,error);
    printf("Root = %f\n",result);
}