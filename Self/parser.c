#include <stdio.h>
#include <string.h>
/*
Link to the tutorial : https://youtu.be/7uBBK6H3rTw?si=oTDT2AutnJTjVhq5

*/
void parser(char *str)
{
    int in = 0; // variable to track whether we are inside the tag
    int index = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (str[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)
        {
            str[index] = str[i];
            index++;
        }
    }
    str[index] = '\0';

    // Remove trailing spaces from the beginning
    while (str[0] == ' ')
    {
        // Shift the string to the left
        for (int i = 0; i < strlen(str); i++)
        {
            /* code */
            str[i] = str[i + 1];
        }
    }

    // Remove trailing spaces from the end
    while (str[strlen(str) - 1] == ' ')
    {
        str[strlen(str) - 1] = '\0';
    }
}

void main()
{
    char str[] = "  <h1>    This is a heading text    </h1>  ";
    parser(str);
    printf("The pared string is : ~~%s~~\n", str);
}