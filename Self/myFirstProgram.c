#include <stdio.h>
// myFirstProgram.exe
int main()
{
    // int a,b;
    // printf("Enter the number a \n");
    // scanf("%d",&a);
    // printf("Enter the number b \n");
    // scanf("%d",&b);
    // printf("The sum is %d\n",a+b);

     int subject;
    int math = 15;
    int science = 18;
    int both = 45;
    printf("How many subjects did you pass?: 1. Math only, 2. Science only, 3. Both Math and Science \n");
    scanf("%d", &subject);
    printf("You've chosen the option %d \n",subject);
    if(subject==1){
        printf("You've won %d rupees cz, you've only passed math",math);
    }
    else if(subject==2)
    {
        printf("You've won %d rupees cz, you've only passed science",science);
    }
    else if(subject==3){
        printf("Hurray! you've won %d rupees cz, you've passed both math and science",both);
    }
    else
    {
        printf("Sorry! no gift");
    }
    return 0;
}
