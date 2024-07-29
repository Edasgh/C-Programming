#include <stdio.h>
// gcc b.c -o a
int main()
{
    int month, days_passed = 0;

    printf("Enter the month number (1-12): ");
    scanf("%d", &month);

    switch (month)
    {
    case 12:
        days_passed += 31;
    case 11:
        days_passed += 30;
    case 10:
        days_passed += 31;
    case 9:
        days_passed += 30;
    case 8:
        days_passed += 31;
    case 7:
        days_passed += 31;
    case 6:
        days_passed += 30;
    case 5:
        days_passed += 31;
    case 4:
        days_passed += 30;
    case 3:
        days_passed += 31;
    case 2:
        days_passed += 28;
    case 1:
        days_passed += 31;
        break;
    default:
        printf("Invalid month number.\n");
        return 1;
        // if we use break instead of return 1 then the rest of the code will execute that can show invalid outputs
        // we can't use return 1 in case we've used void main() as the main function
    }

    printf("Number of days passed till the end of month %d: %d\n", month, days_passed);
    return 0;
    /*
    The switch statement starts from the given month and falls through to all preceeding months, adding the days of each month.
    case 12 adds 30 days for November, case 11 adds 31 days for October, and so on.
    The default case handles invalid month numbers.
    The program outputs the total number of days passed until the end of the input month.
    */
}
