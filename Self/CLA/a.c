#include <stdio.h>
// gcc a.c -o a
//.\a.exe

// tutorial-1 on command line arguments

void main(int argc, char const *argv[])
{
    // printf("The value of argc is %d\n", argc);
    // printf("The value of 1st element of argv is %s\n", argv[0]);
    /*
    The value of argc is 1
    The value of 1st element of argv is C:\Users\edas2\Desktop\C Programming\Self\CLA\a.exe
     */

    // After giving arguments to command line
    //  .\a.exe hello arg
    // The value of argc is 3

    // printing all the values of argv
    printf("The value of argc is %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("The argument at %d is %s\n", i, argv[i]);
    }

    /*
    OUTPUT :

      .\a.exe hello arg secondarg third_arg fourth_arg fifth and last
        The value of argc is 9
        The argument at 0 is C:\Users\edas2\Desktop\C Programming\Self\CLA\a.exe
        The argument at 1 is hello
        The argument at 2 is arg
        The argument at 3 is secondarg
        The argument at 4 is third_arg
        The argument at 5 is fourth_arg
        The argument at 6 is fifth
        The argument at 7 is and
        The argument at 8 is last


    */
}
