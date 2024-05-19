#include <stdio.h>
//gcc fnCalling.c -o fc
// .\fc.exe
// call by reference example
void swap(int *x,int *y)
{
int temp;
temp =*x;
*x=*y;
*y=temp;
}
void changeVal(int *a)
{
    *a=859;
}
//QUIZ:Given two numbers a and b, add them, subtract them and assign them to a and b
void opr(int *a,int *b)
{
 int add,sub;
 add=*a+*b;
 sub=*a-*b;
 *a=add;
 *b=sub;

}
void main()
{
 int a=78,b=24;
 printf("The value of a is %d and of b is %d\n",a,b); //The value of a is 78 and of b is 24
//  swap(&a,&b); // values of actual parameters can be changed in call by reference functions
//  printf("The new value of a is %d and of b is %d\n",a,b);
//  changeVal(&a);
//  printf("The new value of a is %d\n",a);
opr(&a,&b);
 printf("The new value of a is %d and of b is %d\n",a,b); //The new value of a is 102 and of b is 54

}