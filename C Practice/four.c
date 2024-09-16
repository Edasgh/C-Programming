#include <stdio.h>

void single_comments(FILE *ptr1,char c)
{
   char d;
   while((d=fgetc(ptr1))!=EOF)
   {
     if(d=='\n')
     {
        return;
     }
   }
}


void block_comments(FILE *ptr1,char c)
{
    char d,e;
    while((d=fgetc(ptr1))!=EOF)
    {
        if(d=='*')
        {
            e = fgetc(ptr1);
            if(e=='/')
            {
                return;
            }
        }
    }
}


void check_comments(FILE *ptr1, FILE *ptr2,char c)
{
    char d;
    if(c=='/')
    {
       if((d=fgetc(ptr1))=='/')
        {
             single_comments(ptr1,c);
        }
        else if(d == '*')
        {
            block_comments(ptr1,c);
        }
        else{
            fputc(c,ptr2);
            fputc(d,ptr2);
        }

    }
    else{
        fputc(c,ptr2);
    }
}

void main()
{
    FILE *fp1, *fp2;

    fp1 = fopen("test.txt","r");
    fp2 = fopen("result.txt","w");

    if(fp1==NULL || fp2==NULL)
    {
        printf("Can't open files");
    }

    char c;

    while((c=fgetc(fp1))!=EOF)
    {
          check_comments(fp1,fp2,c);
    }

    printf("Comments removed successfully\n");
    fclose(fp1);
    fclose(fp2);
}