#include <stdio.h>
#include <stdlib.h>

struct complex{
  int real;
  int imaginary;
};


struct complex add(struct complex num1,struct complex num2)
{
 int real1 = num1.real;
 int imaginary1 = num1.imaginary;
 int real2 = num2.real;
 int imaginary2 = num2.imaginary;

 struct complex sum;
 sum.real = real1+real2;
 sum.imaginary = imaginary1+imaginary2;
 
 return sum;
 
}

struct complex mult(struct complex num1,struct complex num2)
{
 int real1 = num1.real;
 int imaginary1 = num1.imaginary;
 int real2 = num2.real;
 int imaginary2 = num2.imaginary;
 // (x+iy) (p+iq) //xp+iyp+ixq-yq
 struct complex product;
 product.real = (real1*real2)+(-1)*(imaginary1*imaginary2);
 product.imaginary = (real2*imaginary1)+(real1*imaginary2);
 
 return product;
 
}

void main()
{
 
 struct complex num1,num2;
 
 printf("Enter the first complex number (real imaginary) : ");
 scanf("%d %d",&(num1.real),&(num1.imaginary));

 printf("\nEnter the second complex number (real imaginary) : ");
 scanf("%d %d",&(num2.real),&(num2.imaginary));

 printf("\nThe first complex number is : %d+i%d\n",num1.real,num1.imaginary);
 printf("The second complex number is : %d+i%d\n",num2.real,num2.imaginary);
 
 struct complex sum,product;
 
 int op;
 
 while(1)
 {
 printf("Now select an operation to perform -> \n1.Addition of complex no.s , \n2.Multiplication of complex no.s\n 3. Exit\n Select : ");
 scanf("%d",&op);
 
 switch(op)
 {
   case 1:
    sum = add(num1,num2);
   printf("Sum of the complex numbers is : %d+i%d\n",sum.real,sum.imaginary);
   break;
   case 2: 
  product = mult(num1,num2);
  printf("Product of the complex numbers is : %d+i%d\n",product.real,product.imaginary);
  break;
  case 3: 
  exit(0);
  break;
  default:
  printf("Invalid option.");
 

 }
 }

}