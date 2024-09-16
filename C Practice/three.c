#include <stdio.h>


void main()
{
    int n;
    printf("Enter a number here : ");
    scanf("%d",&n);

    int i=0,j=0,k=0;

    for(i=1;i<=n;i++)
    {
        for(k=n-i;k>=0;k--)
        {
            printf(" ");
        }

        for(j=1;j<=2*i-1;j++)
        {
           if(i==n||j==1||j==2*i-1){
           printf("*");
           }
           else
           {
            printf(" ");
           }
        }
        printf("\n");

    }
    for(i=0;i<=n-1;i++)
    {
        for(j=1;j<=n-1;j++)
        {
            printf(" ");
        }
        for(k=0;k<1;k++)
        {
            printf("%d",11);
        }
        printf("\n");
    }

    printf("\n\n\n");

    for(i=1;i<=n;i++)
    {
        int num=1;
        for(j=1;j<=i;j++)
        {
            printf("%d",num);
            num = num * (i-j)/j;


        }
        printf("\n");
    }

}