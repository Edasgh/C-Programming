#include <stdio.h>
// wild pointer in c

// gcc wildptr.c -o wildptr

void main()
{
    int a = 25;
    int *ptr; // now this is a wild pointer (not a good practice to write in programs)
    //*ptr=34; //not a good practice | The value 34 get assigned to the garbage address
    printf("%x\n", ptr);
    printf("%d\n", *ptr);
    ptr = &a; // this is now no longer a wild pointer
    printf("%x\n", ptr);
    printf("%d\n", *ptr);

    /*
    OUTPUT :

    26b000
    0
    61ff18
    25

    */

    /*

    //After another run
    33d000
    0
    61ff18
    25

    */
}