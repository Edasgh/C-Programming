#include <stdio.h>

int power(int a, int b)
{
    if(b==1)
    {
        return a;
    }

    return a*power (a,b-1);

}

void main()
{
    // int num;
    // printf("Enter a number here : ");
    // scanf("%d",&num);

    // int pown;
    // pown = power(num,2);

    // printf("%d^%d = %d ",num,2,pown);

    int month;
    printf("Select an option : 1.Jan , 2.Feb, 3.Mar, 4.Apr, 5.May, \n6.Jun, 7.Jul, 8.Aug, 9.Sep, 10.Oct, 11.Nov, 12.Dec\n");
    scanf("%d",&month);
    int days =0;

    switch(month)
    {
       case 12:
       days+=31;
       case 11:
       days+=30;
       case 10:
       days +=31;
       case 9:
       days+=30;
       case 8:
       days+=31;
       case 7:
       days+=31;
       case 6:
       days+=30;
       case 5:
       days+=31;
       case 4:
       days+=30;
       case 3:
       days+=31;
       case 2:
       days+=28;
       case 1:
       days +=31;
       break;
       default:
       printf("Invalid choice");
    }

    printf("Total days spent = %d ",days);


}