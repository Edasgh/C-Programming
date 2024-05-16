#include <stdio.h>
// gcc pointers.c -o pn
// .\pn.exe

void main()
{
// int a =73;
// int* p=&a; // p is a pointer to a : p stores the address of a
// int *pt=NULL;
// // printf("The value of a is %d\n",*p);
// // printf("The address of a is %x\n",p);
// // printf("The address of p is %x\n",&p);
// printf("The value of a is %d\n",*pt);
// printf("The address of a is %p\n",pt);
// printf("The address of pt is %p\n",&pt);

//////// Pointer Arithmetic /////////

// int a =34;
// int *ptra=&a; // ptra is a pointer to a
//  char a ='3';
//  char *ptra=&a; // ptra is a pointer to a
// printf("%d\n",ptra);
//  ptra++; // at first prints the value then increments if tried to print ptra++
// ++ptra;//at first increments then, prints the value if tried to print ++ptra
// printf("%d\n",ptra); // same value as after ptra++ as after ++ptra
//  printf("%d\n",ptra+1);
// printf("%lu",sizeof(ptra));


/////Array Pointers/////
int arr[6]={9,1,2,3,5,7};
int *ptr = arr;
// printf("The value at the first element of the array is %d\n",arr[0]); // *(arr) = arr[0]
// printf("The value at the first element of the array is %d\n",*(arr));
// printf("The value at the second element of the array is %d\n",*(arr+1)); // *(arr+i) = arr[i]
// printf("The value at the 5th element of the array is %d\n",*(&arr[5])); // *(&arr[i]) = arr[i]
// printf("The address of the first element of the array is %d\n",&arr[0]);
// printf("The address of the first element of the array is %d\n",arr); // arr = &arr[0]
// printf("The address of the second element of the array is %d\n",&arr[1]);
// printf("The address of the second element of the array is %d\n",arr+1);// &arr[i] = arr+1
// arr++ is not a valid statement : arr is a constant
printf("%d\n",ptr);
ptr++;
printf("%d\n",ptr);





}
