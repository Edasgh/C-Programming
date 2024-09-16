#include <stdio.h>
#include <string.h>

void main()
{
 FILE *fp1, *fp2;
 
 fp1 = fopen("test.txt","r");
 fp2 = fopen("file2.txt","w");

 if(fp1==NULL || fp2==NULL)
  {
    printf("Can't open files\n");
  }

  char str[100];

  while(fscanf(fp1,"%s",str)!=EOF)
  {
     if(strlen(str)>15)
      {
       fprintf(fp2,"%s",str);
      }
  }
  printf("Content copied successfully!");
  
  fclose(fp1);
  fclose(fp2);
}