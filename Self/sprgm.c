#include <stdio.h>
#include <conio.h>
#define MAX 100 // this is a constant

int a = 50;
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
}
void display()
{
    printf("World from display");
}