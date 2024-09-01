#include <stdio.h>
#include <string.h>

void main()
{
    // int num;
    // // int num,sum=0;
    // printf("Enter a number : ");
    // scanf("%d",&num);

    // for(int i=1;i<=num;i++)
    // {
    //    if(num%i==0 && i!=num)
    //    {
    //     sum+=i;
    //    }
    // }

    // if(sum==num)
    // {
    //     printf("%d is a perfect number",num);
    // }
    // else
    // {
    //     printf("%d is not a perfect number", num);
    // }


// sum of factorials numbers till n
// int fact =1;
// sum=0;
//     for(int i=1;i<=num;i++)
//     {
//        fact*=i;
//        sum+=fact;
//     }

    
//         printf("The sum of factorials till %d is  %d",num,sum);
   
// sum of inverse of numbers till n
// float inv =1;
// float sum=0;
//     for(int i=1;i<=num;i++)
//     {
//        inv = (float) (1/(float)i);
//        sum+=inv;
      
//     }

    
//         printf("The sum of inverse of numbers till %d is  %f",num,sum);


//sum of digits
// int sum=0,digit=0;
// int n;
// n=num;
// while(n>0)
// {
//     digit = n%10;
//     sum+=digit;
//     n/=10;
// }

// printf("Sum of digits of %d is %d",num,sum);

//reverse a number
    // int sum = 0, digit = 0;
    // int n;
    // n=num;
    // while(n>0)
    // {
    //     digit = n%10;
    //     sum=sum*10+digit;
    //     n/=10;
    // }

    // printf("Reverse of %d is %d", num, sum);


//reverse a string

    int sum = 0, digit = 0;
    char temp;
    char str[]="Eshita";
    char str2[80];
    strcpy(str2,str);
    int size = strlen(str);

    char *ptr;
    ptr=str;
    int start =0;
    int end = size -1;

    while(start<end)
    {
        temp = ptr[start];
        ptr[start]=ptr[end];
        ptr[end]=temp;

        start++;
        end--;
    }

    printf("%s\n",str);

    if(strcmp(str,str2)==0)
    {
        printf("%s is a palindrome string",str2);
    }
    else
    {
        printf("%s is not a palindrome string", str2);
    }

    
}