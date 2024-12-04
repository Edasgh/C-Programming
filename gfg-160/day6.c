#include <stdio.h>
#include <stdlib.h>

/*
You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array.

Note: The answer should be returned in an increasing format.

Examples:

1.
Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more than n/3 times


2.
Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: no candidate occur more than n/3 times.



*/

int *findMajority(int arr[], int n, int *resultSize)
{
    // initialize the candidates & counts for each candidate
    int el1 = -1, el2 = -1, count1 = 0, count2 = 0;
    // according to moore's voting algorithm : the elements appear more than n/3 times can be 2 elements maximum
    //  the elements appear more than n/2 times can be 1 element maximum
    int *arr1 = (int *)malloc(2 * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (el1 == arr[i])
        {
            count1++;
        }
        else if (el2 == arr[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            el1 = arr[i];
            count1++;
        }
        else if (count2 == 0)
        {
            el2 = arr[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    // verify the elements / candidates
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
        {
            count1++;
        }
        else if (arr[i] == el2)
        {
            count2++;
        }
    }

    int idx = 0;

    if (count1 > (n / 3) && count2 > (n / 3))
    {
        arr1[idx++] = el1;
        arr1[idx++] = el2;
    }
    else if (count1 > (n / 3))
    {
        arr1[idx++] = el1;
    }
    else if (count2 > (n / 3))
    {
        arr1[idx++] = el2;
    }

    *resultSize = idx;
    int temp, flag;
    // sort the arr1 using bubble sort method
    for (int i = 0; i < idx - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < idx - 1 - i; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0)
        {
            break;
        }
    }

    return arr1;
}
