#include <stdio.h>


void main()
{
 int n,num,remainder;
 printf("Enter a number here :");
 scanf("%d",&n);
 num=n;

 int i=0,fact=1,product=1,sum=0,sum2=0;
 
 int digits=0;
 while(num>0)
 {
   
  remainder = num%10;
  digits++;
  num/=10;

  
 }

 num = n;

 while(num>0)
 {
   remainder = num%10;
   i=1;
   while(i<=digits)
   {
    product*=remainder;
    i++;
   }
   sum+=product;
   product=1;
   num/=10;
 }


 num =n;
 
 while(num>0)
 {
   remainder = num%10;
   i=1;
   while(i<=remainder)
   {
     fact*=i;
     i++;
   }
   sum2+=fact;
   fact=1;
   num/=10;
 }


 if(sum==n)
 {
  printf("%d is an armstrong number",n);
 }
 else if(sum2==n)
 {
  printf("%d is a krishnamurthy number",n);
 }
 else
 {
  printf("%d is neither an armstrong number nor a krishnamurthy number",n);
 }


 
 
}


