#include <stdio.h>

int main()
{
    int i, age;
    for (i = 0; i < 5; i++)
    {
        //   printf("%d\n",i);
        printf("Enter your age\n");

        scanf("%d", &age);
        //   if(age>30){
        //     printf("Age is greater than 30\n");
        //     break; //without the break statement, the program will run 4 times
        //   }else{
        //     printf("Here's what the next statement is for the age=%d\n",age);
        //   }
        // switch-case statement
        // switch(age){
        //     case 20:
        //     printf("Age is 20\n");
        //     break; // if age is 20 then at second input it won't read the case 45 logic and will go to the default code
        //     case 45:
        //     printf("Age is 45\n");
        //     default:
        //     printf("Your entered age is :%d\n",age);
        // }

        // continue-statement

        if (age > 10)
        {
            continue; // when age>10 the control will go back to the line 1 of the loop
        }

        printf("We haven't come up with any of the continue statements\n"); // it will print when age<10
    }
    return 0;
}