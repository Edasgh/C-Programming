#include <stdio.h>
#include <string.h> //library which contains string methods

void printStr(char str[])
{
    int i=0;
    while (str[i]!='\0')
    {
        printf("%c",str[i]);
        i++;
    }

}
void main()
{
//char str[]={'E','s','h','i','t','a','\0'}; // '\0' is the null character
// char str[]="Eshita";//no need of null character in this syntax
// puts(str); // to print a string
// printf("%s",str); //also prints a string


// char str2[6];
// printf("Enter the string of 6 characters\n");
// gets(str2);// to take input of a string
// printf("The string is : %s\n",str2);


// printStr(str);



///String Methods////
// char s1[]="Eshita";
// char s2[]="Rama";
// char s3[359];

// printf("%s\n",strcat(s1,s2)); // concatenates s2 into s1
// printf("Length of s1 is %d\n",strlen(s1));
// printf("Length of s2 is %d\n",strlen(s2));
// printf("The reversed version of s1 is :\n");
// printf("%s\n",strrev(s1)); // reverses the string character by character
// // OUTPUT : atishE
// printf("The reversed version of s2 is :\n");
// printf("%s\n",strrev(s2)); // reverses the string character by character
// // OUTPUT : amaR

// strcpy(s3,strcat(s1,s2)); //cz we can't write like this : s3=strcat(s1,s2); it will give error : assignment of expression to an array
// printf("s3 is : %s",s3);

//strcmp() generally returns ASCII difference of first unmatching character or 0, values greater or less than 0
// printf("The strcmp for s1, s2 is %d\n",strcmp(s1,s2)); // Output : -1 , E comes first in ASCII then, R (Address of E is lesser than R)
// printf("The strcmp for s1, s3 is %d\n",strcmp(s1,s3)); // Output : 0
// printf("The strcmp for s2, s3 is %d\n",strcmp(s2,s3)); // Output : 1



//Quick Quiz : allow user to enter two strings then print saying : str1 is a friend of str2 and then concat str1 and str2 in str3 and print it
char str1[35];
char str2[35];
char str3[70];

printf("Enter two strings here :\n");
printf("Enter the first string :");
gets(str1);
printf("Enter the second string :");
gets(str2);
printf("\n%s is a friend of %s\n",str1,str2);
strcpy(str3,strcat(str1,str2));
printf("The string str3 is : %s\n",str3);



}