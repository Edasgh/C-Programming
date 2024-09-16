#include <stdio.h>


void main()
{
 //twin prime numbers
 int n;
 printf("Enter a number here :");
 scanf("%d",&n);
 int i=0;
 for(i=1;i<=n;i++)
 {
   if(i%2!=0 && (i+2)%2!=0)
     {
       printf("(%d, %d) are twin prime numbers\n",i,i+2);
     }
  }
}