#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
    FILE *ptr;
    ptr = NULL;
    int words=0,characters=0,inword=0;

    char c;
    char fname[50];
    printf("\n\nCount the number of words and characters in a file:\n");
    printf("Enter the file name you want to open : ");
    scanf("%s",fname);

    ptr = fopen(fname,"r");

    if(ptr==NULL)
    {
      printf("Error while file opening\n");
    }
    else
    {
         while(fscanf(ptr,"%c",&c)!=EOF)
         {
            printf("%c",c);
            characters++;

            if(isspace(c))
            {
              inword=0;
            }
            else if(!inword)
            {
              inword = 1;
              words++;
            }
         }

         fclose(ptr);

         printf("\nThe number of words in the file %s are: %d\n", fname, words);
         printf("The number of characters in the file %s are: %d\n", fname, characters);
    }
}