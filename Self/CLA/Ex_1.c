#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// gcc Ex_1.c -o b
//.\b.exe

// Command line calculator

void main(int argc, char const *argv[])
{
    char op[20]; // add/sub/div/mult
    strcpy(op, argv[1]);
    int fnum, snum;
    if (atoi(argv[2]) == 0 || atoi(argv[3]) == 0)
    {
        printf("You missed to enter a number here!\n");
    }
    else
    {

        if (atoi(argv[2]) != 0)
        {

            fnum = atoi(argv[2]); // atoi function converts the string in argv[2] into an integer
        }

        if (atoi(argv[3]) != 0)
        {

            snum = atoi(argv[3]);
        }

        if (strcmp(op, "add") == 0)
        {

            printf("%d + %d = %d\n", fnum, snum, (fnum + snum));
        }
        else if (strcmp(op, "sub") == 0)
        {

            printf("%d - %d = %d\n", fnum, snum, (fnum - snum));
        }
        else if (strcmp(op, "div") == 0)
        {

            printf("%d / %d = %d\n", fnum, snum, (fnum / snum));
        }
        else if (strcmp(op, "mult") == 0)
        {

            printf("%d X %d = %d\n", fnum, snum, (fnum * snum));
        }
        else
        {
            printf("Invalid operator");
        }
    }
}