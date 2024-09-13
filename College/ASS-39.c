#include <stdio.h>
#include <stdlib.h>

// gcc ASS-39.c -o a

int main(int argc, char *argv[])
{
    FILE *ptr1, *ptr2;
    ptr1 = NULL, ptr2 = NULL;

    char c;

    if (argc != 3)
    {
        printf("File names aren't entered\n");
        return 1;
    }

    ptr1 = fopen(argv[1], "r");
    if (ptr1 == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }

    ptr2 = fopen(argv[2], "w+");

    if (ptr2 == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }

    while (fscanf(ptr1, "%c", &c) != EOF)
    {
        fprintf(ptr2, "%c", c);
    }

    printf("\nFile Content copied successfully!\n");

    fclose(ptr1);
    fclose(ptr2);

    return 0;
}