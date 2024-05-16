# include <stdio.h>
// gcc .\recrsn.c -o rec
//.\rec.exe
int factorial(int num);
int main(){
    int number;
   printf("Enter the number to you want the factorial of\n");
   scanf("%d",&number);
   printf("The factorial of %d is %d\n",number,factorial(number));
    return 0;
}

int factorial(int num) // recursive function
{
    if(num==1||num==0){
        return 1;
    }
    else{
        return (num*factorial(num-1));
    }
}