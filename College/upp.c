#include <stdio.h>
// gcc upp.c -o a
void main()
{
    // Convert a string to uppercase
    char str[] = "Hello friends";
    int size = sizeof str;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }

    printf("%s", str); // HELLO FRIENDS
}