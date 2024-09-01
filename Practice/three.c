#include <stdio.h>


void main()
{
    // int n;
    // int num;
    // printf("Enter a number here : ");
    // scanf("%d",&n);
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=n-i;j>=0;j--)
    //     {
    //         printf(" ");
    //     }
    //     num = 1;
    //     for(int k=1;k<=i;k++)
    //     {
    //         printf("%4d",num);
    //         num = num * (i-k)/k;

    //     }
    //     printf("\n");

    // }

    // FILE *inputFile;
    // inputFile = NULL;
    // inputFile = fopen("new.txt","r");
    // char c;
    // int n,count=0,sum=0;
    // while(fscanf(inputFile,"%d",&n)!=EOF)
    // {
      
    //     printf(" %d ",n);
    //     sum+=n;
    //     count++;
    // }

    // int avg = sum/count;
    // printf("\nAverage of the numbers are : %d",avg);

    // fclose(inputFile);

    //Armstrong number
    // int n,num,power=0,digit=0,i,sum=0,prod;
    // printf("Enter a number : ");
    // scanf("%d",&n);
    // num=n;
    // //153

    // while(n>0)
    // {
    //   n/=10;
    //   power++;
    // }
 

    // n=num;

    // while(n>0)
    // {
    //   digit = n % 10;
    //   prod=1;
    //   i=0;
    //   while(i<power)
    //   {
    //     prod=prod*digit;
    //     i++;
    //   }
    //   sum=sum+prod;
    //   n/=10;
    // }

    // if(sum==num)
    // {
    //     printf("%d is an armstrong number",sum);
    // }
    // else
    // {
    //     printf("%d is not an armstrong number", sum);
    // }




    //inverted pyramid
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);
    int i=0,j=0,k=0;

    for(i=1;i<=num;i++)
    {
        for(j=num-i;j>=0;j--)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("%c",(char)(k+64));
        }
        for(k=i-1;k>=1;k--)
        {
            printf("%c",(char)(k+64));
        }
        printf("\n");

    }
}