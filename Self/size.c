#include <stdio.h>
#include <math.h>

int main()
{
    // int a=5;
    // int b=6;
    // printf("%lu",sizeof(int));
    // printf("\n");
    // printf("%lu",sizeof(char));
    // printf("a=b ? %d\n",a==b);
    // printf("a<=b ? %d\n",a<=b);
    // printf("a>=b ? %d\n",a>=b);
    // printf("a!=b ? %d\n",a!=b);
    // printf("a>b ? %d\n",a>b);
    // printf("a<b ? %d\n",a<b);
    // printf("a+b = %d\n",a+b);
    // printf("a-b = %d\n",a-b);
    // printf("a*b = %d\n",a*b);
    // printf("a/b = %d\n",a/b);
    // printf("a\%b= %d\n",a%b);
    // printf("a&&b = %d\n",a&&b);
    // printf("a||b = %d\n",a||b);

    int age,marks;
    printf("Enter your age \n");
    scanf("%d", &age);
    printf("You are %d years old so,...\n", age);
    // Here we have our if else statement
    // if (age > 18)
    // {
    //     printf("Yeap! you can drive \n");
    // }
    // else if (age < 18)
    // {
    //     printf("No, you can't drive now");
    // }
    // else
    // {
    //     printf("You can start learning how to drive by now!");
    // }
    //Here we have switch-case statement
    switch(age)
    {
        case 4:
        printf("Your age is 4");
        break;
        case 14:
        printf("Your age is 14\n");
        printf("Enter your marks \n");
        scanf("%d",&marks);
        switch (marks)
        {
        case 30:
        printf("Your marks are 30");
            break;
        
        default:
        printf("Your marks are not 30");
            break;
        }
         break;
        case 24:
        printf("Your age is 24");
        break;
    }
    return 0;
}