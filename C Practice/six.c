#include <stdio.h>

void main()
{
  int n;
  printf("Enter a number here :");
  scanf("%d",&n);
  
  int i,j,k,num;
  for(i=1;i<=n;i++)
   {
     for(j=1;j<=n-i;j++)
        {
          printf("  ");
         }
     num = 1;
     for(k=1;k<=i;k++)
      {
          printf("%4d",num);
          num = num * (i-k)/k;
      }
     printf("\n");
    }
  
}