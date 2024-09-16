#include <stdio.h>

typedef struct
{
 int meters;
 int centimeters;
} Distance;


void main()
{
 Distance v1,v2;
 printf("Enter the first distance (m cm) : ");
 scanf("%d %d",&(v1.meters),&(v1.centimeters));

 printf("\nEnter the second distance (m cm) : ");
 scanf("%d %d",&(v2.meters),&(v2.centimeters));

 int total1 = v1.meters*100+v1.centimeters;
 int total2 = v2.meters*100+v2.centimeters;

 int difference = total1>total2?total1-total2:total2-total1;
 
 printf("Difference between two distances is: %d cm\n",difference);



}