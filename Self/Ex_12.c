#include <stdio.h>
#include <string.h>

// gcc Ex_12.c -o tw
// .\tw.exe
// Author : Eshita Das

void main()
{
    char letter[] = "Thanks ";
    char nm[55];
    printf("Hello user! Enter your name : ");
    gets(nm);
    strcat(letter, nm);
    strcat(letter, " for purchasing ");
    char item[55];
    printf("Now enter the name of Item : ");
    gets(item);
    strcat(letter, item);
    strcat(letter, " from our outlet ");
    char outlet[55];
    printf("Now enter the outlet name (Enter _ underscore separator only [instead of space]) \n: ");
    gets(outlet);
    strcat(letter, outlet);
    strcat(letter, ".");
    strcat(letter, "\nPlease visit our outlet ");
    strcat(letter, outlet);
    strcat(letter, " for any kind of problems. We plan to serve you again soon.");

    char final[88];
    strcpy(final, letter);

    FILE *ptr = NULL;
    ptr = fopen("12.txt", "w");
    fprintf(ptr, "%s", final);
    printf("Reciept generated Successfully!\n");
    fclose(ptr);
}