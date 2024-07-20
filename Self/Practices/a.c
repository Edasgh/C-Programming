#include <stdio.h>
// gcc a.c -o a
//.\a.exe
int isPrime(int num)
{
    int count = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    int num, prime;
    printf("Enter a number :");
    scanf("%d", &num);
    prime = isPrime(num);

    if (prime)
    {
        printf("%d is a prime number", num);
    }
    else
    {
        printf("%d is not a prime number", num);
    }
}