#include <stdio.h>
// gcc four.c -o a
void main()
{
    // int i = 20, k = 0, j;
    // for (j = 1; j < i; j = i + 4 * (i / j))
    // {
    //     k += j < 10 ? 4 : 3;
    // }
    // printf(" %d ", k); // 4

    /////////////////////////////////////////////////////////////////

    // insert odd elements into the 2nd array and even elements into the 3rd array
    // int size, count2 = 0, count3 = 0;
    // printf("Enter the size of the array : ");
    // scanf("%d", &size);
    // int arr[size], arr2[30], arr3[30];
    // for (int i = 0; i < size; i++)
    // {
    //     printf("Enter value at index %d : ", i);
    //     scanf("%d", &arr[i]);
    // }
    // printf("\nPrinting the first array : \n");
    // for (int i = 0; i < size; i++)
    // {
    //     printf(" %d ", arr[i]);
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] % 2 == 0)
    //     {
    //         arr3[count3] = arr[i];
    //         count3++;
    //     }
    //     else
    //     {
    //         arr2[count2] = arr[i];
    //         count2++;
    //     }
    // }
    // printf("\nPrinting the second array : \n");
    // for (int i = 0; i < count2; i++)
    // {
    //     printf(" %d ", arr2[i]);
    // }
    // printf("\nPrinting the third array : \n");
    // for (int i = 0; i < count3; i++)
    // {
    //     printf(" %d ", arr3[i]);
    // }

    /*
Enter the size of the array : 5
Enter value at index 0 : 12
Enter value at index 1 : 23
Enter value at index 2 : 56
Enter value at index 3 : 78
Enter value at index 4 : 90

Printing the first array :
 12  23  56  78  90
Printing the second array :
 23
Printing the third array :
 12  56  78  90
    */

    /////////////////////////////////////////////////////////////////////////

    // Check if a number is a armstrong number or not

    int num, totalDigits = 0, sum = 0, product = 1, d;
    printf("Enter a number : ");
    scanf("%d", &num);
    int n = num;
    while (num > 0)
    {
        num /= 10;
        totalDigits++;
    }

    int i = totalDigits;
    num = n;
    while (num > 0)
    {
        d = num % 10;
        while (i > 0)
        {
            product *= d;
            i--;
        }
        sum += product;
        product = 1;
        i = totalDigits;
        num /= 10;
    }

    if (sum == n)
    {
        printf("%d is an armstrong number\n", n);
    }
    else
    {
        printf("%d is not an armstrong number\n", n);
    }

    /*
Enter a number : 153
153 is an armstrong number

Enter a number : 1111
1111 is not an armstrong number
    */
}