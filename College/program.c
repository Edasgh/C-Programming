#include <stdio.h>
#include <stdlib.h>

FILE *fp, *fp2;

void block_comment()
{

    char d, e;

    while ((d = fgetc(fp)) != EOF)
    {

        if (d == '*')
        {
            e = fgetc(fp);
            if (e == '/')
                return;
        }
    }
}

void single_comment()
{
    char d;

    while ((d = fgetc(fp)) != EOF)
    {

        if (d == '\n')
            return;
    }
}
void remove_comments(char c)
{
    char d;

    if (c == '/')
    {
        if ((d = fgetc(fp)) == '*')
            block_comment();
        else if (d == '/')
        {
            single_comment();
        }
        else
        {
            fputc(c, fp2);
            fputc(d, fp2);
        }
    }
     else
     {
        fputc(c, fp2);
     }
}

int main(void)
{
    char c;
    fp = fopen("test.txt", "r");
    fp2 = fopen("file2.txt", "w");
    if(fp==NULL || fp2==NULL)
    {
       printf("Can't open file\n");
       return 1;
    }
    while ((c = fgetc(fp)) != EOF)
    {
        remove_comments(c);
    }
    fclose(fp);
    fclose(fp2);

    return 0;
}
