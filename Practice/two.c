#include <stdio.h>

void main()
{
    FILE* ptr= NULL;
    ptr = fopen("new.txt","r");
    char c;
    int n;
    FILE *evenFile , *oddFile;
    if(ptr!=NULL)
    {
       evenFile= fopen("even.txt","w");
       oddFile=fopen("odd.txt","w");
    }
    while(fscanf(ptr,"%d",&n)!=EOF)
    {
        if(n%2==0)
        {
           fprintf(evenFile,"%d\n",n);
        }
        else{
            fprintf(oddFile,"%d\n",n);
        }

    }

    fclose(ptr);
    fclose(evenFile);
    fclose(oddFile);
}