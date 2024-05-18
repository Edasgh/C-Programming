# include <stdio.h>

//gcc star.c -o star

//QUIZ: Print star pattern and create a function to choose the mode of pattern

void chooseMode(int mode);

void triangle_pattern(int n)
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
   {
     printf("%c",'*');
   }
   printf("\n");
  }
  
}

void reverse_triangle_pattern(int n)
{
 for(int i=0;i<=n;i++)
  {
    for(int j=n-i;j>0;j--)
   {
     printf("%c",'*');
   }
   printf("\n");
  }
}


void chooseMode(int mode)
{
 int option,num;
 option=mode;
 switch(mode)
 {
  case 1 : 
   printf("\nNow, enter a number to view the triangle star pattern of:\n");
  scanf("%d",&num);
  printf("\nPrinting the triangle star pattern\n");
  triangle_pattern(num);
  break;
  case 2:
   printf("\nNow, enter a number to view the reverse triangle star pattern of:\n");
  scanf("%d",&num);
  printf("\nPrinting the reverse triangle star pattern\n");
  reverse_triangle_pattern(num);
  break;
  default:
  printf("\nQuitted successfully\n");
 }
}
void main()
{
  int mode;
  printf("Choose a mode of star pattern printing (press any number except 1 and 2 to quit)\n : 1. Triangle Pattern, 2. Reverse Triangle Pattern \n");
  scanf("%d",&mode);
  chooseMode(mode);
}