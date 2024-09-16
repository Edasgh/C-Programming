#include <stdio.h>
#include <string.h>



void main()
{
  char str[100];
  printf("Enter a sentence :");
  gets(str); 

  char words[100][100];
  char wordToReplace[100];

  printf("\nNow enter the word to replace : ");
  scanf("%s",wordToReplace);

  char newWord[100];
  printf("\nNow enter the new word :");
  scanf("%s",newWord);
  
  //array of strings
  int i=0,j=0,k=0;
  while(str[i]!='\0' && str[i]!='\n')
  {
     if(str[i]!=' ')
      {
         words[j][k++]=str[i];
      }
      else if(k>0)
      {
        words[j][k]='\0';
        j++;
        k=0;
      }
    i++;
   }
   
   if(k>0)
   {
    words[j][k]='\0';
    j++;
   }



   for(i=0;i<j;i++)
   {
     if(strcmp(wordToReplace,words[i])==0)
     {
         strcpy(words[i],newWord);
         break;
     }
    }



   // Reconstructing the sentence
    printf("\nModified sentence: \n");
    for (i = 0; i < j; i++) {
        printf("%s ", words[i]);  // Print each word
       
    }



   

  
  
}