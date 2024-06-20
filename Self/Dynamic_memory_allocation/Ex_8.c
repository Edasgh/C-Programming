#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc Ex_8.c -o Ex_8
//  .\Ex_8.exe
// Author : Eshita Das :)

/*Dynamic Memory Allocation
ABC Pvt Ltd. manages employee records of other companies.
Employee Id can be of any length and it can contain any character
For 3 employees, you have to take 'length of employee id' as input in a length integer variable.
Then, you have to take employee id as an input and display it on screen.
Store the employee id in a character array which is allocated dynamically.
You have to create only one character array dynamically
EXAMPLE:
Employee 1:
Enter no of characters in your eId
45
Dynamically allocate the character array.
*/
int main()
{
    char *ptr;
    int n;
    int employees = 3;
    for (int i = 0; i < employees; i++)
    {
    restart:
        printf("Enter the length of Employee id of Emp.%d : \n", i + 1);
        scanf("%d", &n);
        ptr = (char *)malloc((n + 1) * sizeof(char)); //n is for the employee id and 1 more for the null character : \0

        printf("Enter your Emp. Id :");
        scanf("%s", ptr);

        if (strlen(ptr) <= n)
        {
            printf("\nThe Emp. Id of employee %d is : %s\n", i + 1, ptr);
            free(ptr);
        }
        else
        {
            printf("Sorry number of characters did not match.\n\n");
            free(ptr);
            goto restart;
        }
    }

    return 0;
}