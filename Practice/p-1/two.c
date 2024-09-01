#include <stdio.h>
#include <string.h>

void main()
{
    char str[]="This is a one one two two c code file";

    char str1[30][30];
    int widx=0,lidx=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
        {
            str1[widx][lidx++]=str[i];
        }
        else
        {
            str1[widx][lidx]='\0';
            widx++;
            lidx=0;

        }
    }

    str1[widx][lidx]='\0';
    printf("The words in the sentence are:\n");
 
    for (int i = 0; i <= widx; i++)
    {
        printf("%s\n", str1[i]);
    }


    for (int i = 0; i <= widx; i++)
    {
        printf("%s\n", str1[i]);
        char one[35];
        strcpy(one,str1[i]);
        char two[35] ;
        strcpy(two,str1[i+1]);

        if(strcmp(one,two)==0)
        {
          for(int j=i+1;j<=widx;j++)
          {
            strcpy(str1[j],str1[j+1]);
          }

            widx--;

        }
    }

    for (int i = 0; i <= widx; i++)
    {
        printf("%s\n", str1[i]);
    }
}