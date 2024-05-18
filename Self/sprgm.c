#include <stdio.h>
#include <conio.h>
#define MAX 100 // this is a constant

int a = 50; // this is a normal variable
void display();
void main()
{
    // printf("Hello from main");
    // display();

   //// // Quiz:Multiplication table of a number////
    int num;
    printf("Enter a number to view multiplication table\n");
    scanf("%d", &num);
    printf("The multiplication table of %d is :\n", num);

    // using for loop
    //  for(int i=1;i<=10;i++){
    //      printf("%d X %d = %d\n",num,i,num*i);
    //  }

    // using while loop
    //  int i=1;
    //  while(i<=10){
    //  printf("%d X %d = %d\n",num,i,num*i);
    //  i++;
    //  }

    // using do-while loop
    int i = 0;
    do
    {
        i++;
        printf("%d X %d = %d\n", num, i, num * i);
    } while (i < 10);

//Manual approach
//     int a;
//    printf("Enter the number you want a multiplication table of\n");
//    scanf("%d",&a);
//    printf("Multiplication table of %d is as follows\n",a);
//    printf("%d x 1 = %d\n",a,a*1);
//    printf("%d x 2 = %d\n",a,a*2);
//    printf("%d x 3 = %d\n",a,a*3);
//    printf("%d x 4 = %d\n",a,a*4);
//    printf("%d x 5 = %d\n",a,a*5);
//    printf("%d x 6 = %d\n",a,a*6);
//    printf("%d x 7 = %d\n",a,a*7);
//    printf("%d x 8 = %d\n",a,a*8);
//    printf("%d x 9 = %d\n",a,a*9);
//    printf("%d x 10 = %d\n",a,a*10);
}
void display()
{
    printf("World from display");
}