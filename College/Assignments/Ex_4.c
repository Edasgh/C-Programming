#include <stdio.h>

// Enter an age and check if the user is eligible for vote or not
void main()
{
    int age;
    printf("Enter your age to check your eligibility for vote :\n");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("Congratulations! you are eligible for vote\n");
    }
    else
    {
        printf("Sorry! you're not eligible for vote\n");
    }
}