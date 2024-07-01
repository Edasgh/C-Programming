#include <stdio.h>
#include <string.h>

void main()
{
    FILE *ptr = NULL;
    ptr = fopen("file-1.txt", "r");
    // char c = fgetc(ptr);
    // printf("The character read just now is :   %c\n", c);
    // char c1 = fgetc(ptr);
    // printf("The character read just now is :   %c\n", c1);
    // char c2 = fgetc(ptr);
    // printf("The character read just now is :   %c\n", c2);
    // char c3 = fgetc(ptr);
    // printf("The character read just now is :   %c\n", c3);

    /*
       OUTPUT :

       The character read just now is :   T
       The character read just now is :   h
       The character read just now is :   i
       The character read just now is :   s

        */

    char str[55];
    fgets(str, 54, ptr);
    printf("The read characters are : %s\n", str);
    //  OUTPUT : The read characters are : This is my first file to use with C program

    // ptr = fopen("file-1.txt", "w+");
    // fputc("o", ptr);
    // fputs("This is a string to write", ptr);
    fclose(ptr);
}