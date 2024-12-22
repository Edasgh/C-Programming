#include <stdio.h>
#include <stdlib.h>

int createPol(int pol[])
{
    int i = 0, degree;
    printf("Enter the degree of the polynomial :");
    scanf("%d", &degree);
    for (i = 0; i <= degree; i++)
    {
        printf("Enter the co-eff. of power %d  :", i);
        scanf("%d", &pol[i]);
    }

    return degree;
}

void printPol(int pol[], int degree)
{
    int i;
    printf("\n");
    for (i = degree; i >=0; i--)
    {
        if (i == 0)
        {

            printf(" %dx^%d ", pol[i], i);
        }
        else
        {
            printf(" %dx^%d +", pol[i], i);
        }
    }
}

void addPol(int pol1[], int pol2[], int deg1, int deg2)
{
    int degree = deg2 > deg1 ? deg2 : deg1;
    int pol[degree];
    int i;
    for (i = 0; i <= degree; i++)
    {
        if (i > deg1)
        {
            pol1[i] = 0;
        }

        if (i > deg2)
        {
            pol2[i] = 0;
        }

        pol[i] = pol1[i] + pol2[i];
    }
    printf("\nPrinting the sum of polynomials :\n");
    printPol(pol, degree);
}

void subPol(int pol1[], int pol2[], int deg1, int deg2)
{
    int degree = deg2 > deg1 ? deg2 : deg1;
    int pol[degree];
    int i;
    for (i = 0; i <= degree; i++)
    {
        if (i > deg1)
        {
            pol1[i] = 0;
        }

        if (i > deg2)
        {
            pol2[i] = 0;
        }

        pol[i] = pol1[i] - pol2[i];
    }
    printf("\nPrinting the subtraction of polynomials :\n");
    printPol(pol, degree);
}

void multPol(int pol1[],int pol2[],int deg1, int deg2)
{
    int degree = deg1+deg2;
    int result[degree+1];

    int i,j;
    for(i=0;i<=degree+1;i++)
    {
        result[i] = 0;
    }

    for(i=0;i<=deg1;i++)
    {
        for(j=0;j<=deg2;j++)
        {
            result[i+j] +=pol1[i]*pol2[j];
        }
    }

    printf("\nPrinting the multiplication of polynomials :\n");
    printPol(result,degree);

}

void main()
{

    int pol1[10], pol2[10];
    int deg1, deg2;
    printf("For the 1st polynomial :\n");
    deg1 = createPol(pol1);
    printf("Printing the 1st polynomial :\n");
    printPol(pol1, deg1);
    printf("\nFor the 2nd polynomial :\n");
    deg2 = createPol(pol2);
    printf("Printing the 2nd polynomial :\n");
    printPol(pol2, deg2);
    int op;
    while(1)
    {
    printf("\nNow select an option to perform :\n1.Addition of polynomials,\n2.Subtraction of polynomials,\n3.Multiplication of polynomials,\n4.exit\nSelect : ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            addPol(pol1, pol2, deg1, deg2);
            break;
        case 2:
            subPol(pol1, pol2, deg1, deg2);
            break;
        case 3:
            multPol(pol1, pol2, deg1, deg2);
            break;
        case 4:
          exit(0);
          break;
        default:
        printf("\nInvalid option!");
    }
  
    }
   
  
    


    
}