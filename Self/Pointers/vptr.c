#include <stdio.h>
// gcc vptr.c -o vptr

void main()
{
    int a = 8;
    char b = 'b';
    void *ptr;
    ptr = &a;

    // printf("%x\n", *ptr); // warning: dereferencing 'void *' pointer
    // error: invalid use of void expression

    // typecasting the void pointer to integer and char pointer

    printf("%d\n", *(int *)ptr);
    printf("%x\n", ptr);

    ptr = &b;
    printf("%c\n", *(char *)ptr);
    printf("%x\n", ptr);
}