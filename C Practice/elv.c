#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int octalToDecimal(int octalNum)
{
  int decimal=0,i=0,remainder;
  while(octalNum!=0)
  {
    remainder = octalNum%10;
    decimal+=remainder*pow(8,i);
    i++;
    octalNum/=10;
  }

  return decimal;  
  
  
  
}

long long decimalToBinary (int decimal)
{
  long long binary=0;
   int i=1,remainder;
  while(decimal!=0)
  {
    remainder = decimal%2;
    binary += remainder * i;  
    decimal /= 2;
    i *= 10;
  }
   return binary;
}

int main(int argc , char *argv[])
{
  
  if(argc!=2)
   {
     printf("Octal number isn't entered\n");
     return 1;
   }
  int octal;
  octal = atoi(argv[1]);
   
  int decimal = octalToDecimal(octal);
  
  long long binary;
  
  binary = decimalToBinary(decimal);

  printf("The binary number of %d is %lld\n",octal,binary);


  return 0;
  
}