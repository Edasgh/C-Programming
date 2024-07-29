#include <stdio.h>
#include <string.h>
// gcc one.c -o a
void main()
{
    char str[30];
    printf("Enter a string here to convert to uppercase\n");
    gets(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    printf("Printing the string in uppercase\n");
    puts(str);
}