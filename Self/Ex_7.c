#include <stdio.h>
#include <string.h>
//gcc Ex_7.c -o Ex_7
//.\Ex_7.exe
//Author : Eshita Das :)
struct Driver
{
    char Name[40];
    char Driving_licsence_no[25];
    char Route[35];
    int Kms;
};

void printDetails(struct Driver D){
printf("Driver Details\n");
    printf("--------------\n");
    printf("Name: %s\n",D.Name);
    printf("D.L. Number: %s\n",D.Driving_licsence_no);
    printf("Route: %s\n",D.Route);
    printf("Kilometers: %d\n",D.Kms);
    printf("\n");
}

int main()
{
    int n = 3;
    struct Driver D[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of %d driver : ", i+1);
        scanf("%s", &D[i].Name);
        printf("\n");
        printf("Enter the D.L. no of %s : ", D[i].Name);
        scanf("%s", &D[i].Driving_licsence_no);
        printf("\n");
        printf("Enter the route of %s : ", D[i].Name);
        scanf("%s", &D[i].Route);
        printf("\n");
        printf("Enter the Kms driven by %s : ", D[i].Name);
        scanf("%d", &D[i].Kms);

        printf("\n\n");
    }
    
    for (int i = 0; i <n; i++)
    {
       printDetails(D[i]);
    }
    /*
    //Memory size in bytes || dec = the size of total segment here
     text    data     bss     dec     hex filename
    15292    1616     112   17020    427c .\Ex_7.exe
    */
  

    return 0;
}