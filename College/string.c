#include <stdio.h>
#include <string.h>

void revStr(char *str, int size)
{
    int start = 0;
    int end = size - 1;
    char temp;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char str[25] = "Jayanti";
    int size = 0;
    int i = 0;
    while (i < 25)
    {
        if (str[i] != '\0')
        {

            size++;
        }
        i++;
    }

    printf("%d\n", size);
    puts(str);
    char *s;
    s = str;
    char temp;
    i = 0;
    int j = 0;
    for (i = 0; i < size - 1; i++)
    {
        int min = i;
        if (s[min] > 'A' && s[min] < 'Z')
        {
            s[min] += 32;
        }
        for (j = i + 1; j < size; j++)
        {
            if (s[j] > 'A' && s[j] < 'Z')
            {
                s[j] += 32;
            }
            if ((int)s[j] < (int)s[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = s[i];
            s[i] = s[min];
            s[min] = temp;
        }
    }

    printf("\n");
    puts(str);

    return 0;
}