#include <stdio.h>
//#include "stc2.c"
//cd storage_classes
//gcc stc1.c -o stc1
//.\stc1.exe

//extern int var; //value is getting accessed from "stc2.c" via the include statement and extern keyword

int func1()
{
    static int var=1; // static keyword
    var++;
    printf("%d\n",var);
    return var;
}


void main()
{

register int result = func1(); //register keyword requests the memeory to store the variable in CPU Register : to access the variable fast for frequent use
result = func1();
result = func1();
result = func1();

}