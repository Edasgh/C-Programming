#include <stdio.h>
#include <string.h>


void main()
{
  char name[50];

  
  printf("Enter your name : ");
  fgets(name,50,stdin);
  printf(" %c. ",name[0]);
   
 //Eshita Das


  int size = strlen(name);
 
  int i;
  
  for(i=1;i<size;i++)
   {
       if(name[i]==' ')
       {
            printf("%c.",name[i+1]);
       }
    }

  
 
  
}