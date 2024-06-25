#include <stdio.h>
// gcc nptr.c -o nptr

int main()
{
    int a = 34;
    int *ptr = &a;

    if (ptr != NULL)
    {
        printf("The address of a is %d\n", ptr);
        printf("The value of a is %d\n", *ptr);
    }
    else
    {
        printf("The pointer is a null pointer and it can't be derefferenced!\n");
    }
    return 0;
}