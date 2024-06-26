#include <stdio.h>

/*
The code between #ifdef and #endif will execute if the macro is defined.
For e.g.
#include<stdio.h>
#define DEBUG 3.62
#ifdef DEBUG // This will return True or False
#define GT 39
#endif


#undef PI

#if _POSIX_C_SOURCE >= 200809L


#if !(defined __STRICT_ANSI__ || defined (__NO_MINGW_LFS)) \
 && defined (__MSVCRT__)

 */

/*
Pre-processor Commands:
# define - Substitutes a pre-processor macro.
# include - Inserts a particular header from another file.
# undef - Undefines a preprocessor macro.
# ifdef - Returns true if this macro is defined.
# ifndef - Returns true if this macro is not defined.
# if - Tests if a compile time condition is true.
# else - The alternative for #if. (if #if condition isn't true)
# endif - The statement to end the if statement
# elif - #else and #if in one statement || similar to elseif condition
# pragma - to issue some advanced / special commands to the compiler

*/

/*

Predefined macros in C
__DATE__ => current date in the format :"MMM DD YYYY" ,
__TIME__ => current time in the format : "HH:MM:SS",
__FILE__ => current file name as a string literal,
__LINE__ => current line number as a decimal constant,
__STDC__ => defined as I (one) when the compiler compiles with ANSI standard

 */

#define PI 3.14
#ifdef PI // This will return true or false
#define ID 2.4
#else
#define IP 3.17
#endif
// Here PI is defined so, the #else logic won't execute

void main()
{

    printf("The value of PI is : %.2f\n", PI);
    printf("Pi is defined so , ID = %.2f\n", ID);

    // printf("File name is %s\n", __FILE__);
    // printf("Today's date is %s\n", __DATE__);
    // printf("The current time is %s\n", __TIME__);
    // printf("The current line no. is %d\n", __LINE__);
    // int compileMode;
    // compileMode = __STDC__;
    // if (compileMode == 1)
    // {
    //     printf("This program compiles with ANSI Standard  :) \n");
    // }
    // else
    // {
    //     printf("This program does not compile with ANSI Standard :(\n");
    // }
}