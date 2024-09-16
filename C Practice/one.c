#include <stdio.h>
#include <math.h>

int isMersenne (int n)
{
    int r;
    while(n!=0)
    {
       r = n%2;
       if(r==0)
       {
        return 0;
       }
       n/=2;
    }
    return 1;
}


void main()
{
    int n=500;
    printf("Finding all the mersenne prime numbers from 1 to %d\n",n);

    int i=0,p;
    for(i=0;i<n;i++)
    {
        if(isMersenne(i))
        {
            printf("%d is a mersenne number\n",i);
        }
        

    }

}
