#include <stdio.h>
#include <stdlib.h>
// dangling pointer in c

/*
int *func()
{
    int a = 34;
    int b = 89;
    int sum = a + b;
    return &sum; // warning: function returns address of local variable [-Wreturn-local-addr]
}
*/

int main()
{
    // Case : 1
    int *ptr = (int *)malloc(7 * sizeof(int));
    ptr[0] = 23;
    ptr[1] = 33;
    ptr[2] = 44;
    // printf("%d\n", ptr[0]);

    free(ptr); // now ptr becomes a dangling pointer
               // printf("%d\n", ptr[0]); // prints garbage value

    // Case : 3
    // { //scope should be in any function
    //     int val = 45;
    //     ptr = &val;
    //     printf("%d\n", *ptr);
    // }
    // now ptr becomes a dangling pointer

    printf("%d\n", *ptr);

    // Case : 2
    //  ptr = func();// now ptr becomes a dangling pointer || that function returns address of a local variable
    //  printf("%d\n", *ptr);

    return 0;
}