#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int x){
    int f =1, i=1;
    for(i=1;i<=x;i++){
        f*=i;
    }

    return f;
}


void main(){
    printf("Newton forward interpolation\n");
    int n;
    printf("Enter the length of data : ");
    scanf("%d",&n);

    float table[n][n+1];
    printf("Enter the x values : \n");
    for(int i=0;i<n;i++){
        printf("x[%d] = ",i);
        scanf("%f",&table[i][0]);
    }

    printf("Enter the y values : \n");
    for (int i = 0; i < n; i++)
    {
        printf("y[%d] = ",i);
        scanf("%f", &table[i][1]);
    }

    //building the difference table
    for(int i=2;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
         table[j][i] = table[j+1][i-1] - table[j][i-1];
        }
    }
    //print difference table
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i+1;j++){
            printf("%12.2f",table[i][j]);
        }
        printf("\n");
    }

    float val;
    printf("Enter the x to find f(x) : ");
    scanf("%f",&val);

    float result=0,prod=1,term=0;
    // a+uh = val
    // u = val - a / h
    float a = table[0][0];
    float h = table[1][0] - a;
    float u = (val-a)/h;

    // x0 x1 x2
    // y0 y1 y2
    // f(x) = f(x0) + u/1!* del(f(a))+ u/2!*(u+1)*del(f(a));
    result+=table[0][1];
    printf("%f +",result);
    for(int i=1;i<n;i++){
        prod *= (u-i+1);
        term=(prod/fact(i)) * table[0][i+1];
        result+=term;
        if(i==n-1){
            printf("%f = %f\n",term,result);
        }else{
            printf("%f +",term);
        }
        

    }

    printf("f(%f) = %f\n",val,result);

}
