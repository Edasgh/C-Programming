#include <stdio.h>
// gcc one.c -o a
//.\a.exe
void main()
{

    FILE *ptr = NULL;

    /*
    // Reading a file
    char str[65];
    ptr = fopen("file-1.txt", "r");

    fscanf(ptr, "%s", str);
    printf("The content of the file has :  %s\n", str); // only "this" will be printed bcz a whitespace is between the words of the sentences
    // if there will be "This_word_anotherWord" then it will ge printed since, there's no whitespace
    // if there's no whitespace, there will nothing be printed

    */

       /*
        // Writing to a file
        char str[65] = "This is a customized content to be written to the file";
        ptr = fopen("file-1.txt", "w");// Only the String will be in the file (It deletes all the previous texts and write the string to the file from starting)

        fprintf(ptr, "%s", str);
        printf("The content of the file has :  %s\n", str);
     */

    // Appending text to the file (same as write just open the file as append mode)
    char str[] = "This is a customized content to be appended to the texts of the file";
    ptr = fopen("file-1.txt", "r+");

    fprintf(ptr, "%s", str);
    printf("The content of the file has :  %s\n", str);
    fclose(ptr); // It's mandatory to close file after opening
}