#include <stdio.h>

int Sum(int a, int b)
{
    int c = a + b;
    return c;
}
void printStarPattern(int n); // function declaration

int takeNumber()
{ // example of no parameter with a return value function
    int i;
    printf("Enter a number\n");
    scanf("%d", &i);
    return i;
}

////Quiz : Example of a function without an argument and a return value
void helloMsg()
{
    printf("Hello to this program!\n");
    int t = 11;
    printf("Now, it is %d am", t);
}

void main()
{
    // int num;
    // for (int i = 0; i < 8; i++)
    // {
    //    printf("i=%d\n",i);
    //    for (int j = 0; j <8; j++)
    //    {
    //    printf("j=%d\n",j);
    //     printf("Enter a number, press 0 to exit\n");
    //    scanf("%d",&num);
    //     if(num==0){
    //         goto end;// break statement only quits the control out of the current loop,goto takes the control to a specific label here : "end"
    //     }
    //     printf("Sorry, can't end\n");
    //    }

    // }
    // end:printf("Hello my friendo ,this is the endo");

    //////
    int a = 20, b = 57, c;
    c = Sum(a, b);
    // printf("The sum of the numbers %d and %d is %d\n",a,b,c);
    printStarPattern(6); // function calling

    //  int p= takeNumber();
    //  printf("The number is %d",p);

    // helloMsg();
}
// function definition
void printStarPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (n - i); k++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
    /*
    //OUTPUT :

    ******
     *****
      ****
       ***
        **
         *
    */
}