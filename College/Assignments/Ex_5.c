#include <stdio.h>

int SmallestNum(int num1,int num2, int num3)
{

if(num1<num2 && num1<num3)
{
    return num1;
}
else if(num2<num3 && num2<num1)
{
     return num2;
}
else
{
 return num3;
}


}

void main()
{
    int num_1, num_2, num_3,smallest;
    printf("Enter the first number :\n");
    scanf("%d", &num_1);
    printf("Enter the second number :\n");
    scanf("%d", &num_2);

    printf("Enter the third number :\n");
    scanf("%d", &num_3);


    smallest=SmallestNum(num_1,num_2,num_3);

    printf("The smallest number is : %d\n",smallest);


}