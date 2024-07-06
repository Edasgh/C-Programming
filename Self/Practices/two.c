#include <stdio.h>
#include <stdlib.h>
// gcc two.c -o a
//.\a.exe

struct Date
{
    int day;
    int month;
    int year;
};

int totalMonthDays[12][2] = {{31}, {28, 29}, {31}, {30}, {31}, {30}, {31}, {31}, {30}, {31}, {30}, {31}};

struct Date calculateAge(struct Date dob, struct Date today)
{
    struct Date Age;
    int day = 0, month = 0, year = 0;
    int totalMthDs = 0;
    if (today.month == 2)
    {
        if ((today.year) % 4 == 0)
        {
            totalMthDs = totalMonthDays[(today.month) - 1][1];
        }
        else
        {
            totalMthDs = totalMonthDays[(today.month) - 1][0];
        }
    }
    else
    {

        totalMthDs = totalMonthDays[(today.month) - 1][0];
    }

    year = today.year - dob.year;
    month = today.month < dob.month ? today.month + 12 - dob.month : today.month - dob.month;
    if (today.month < dob.month)
    {
        year -= 1;
    }

    day = today.day < dob.day ? today.day + totalMthDs - dob.day : today.day - dob.day;
    if (today.day < dob.day)
    {
        month -= 1;
    }

    Age.year = year;
    Age.day = day;
    Age.month = month;

    return Age;
}

// age to days ,years & months
void main()
{

    struct Date dob, today, Age;
    dob.day = 0;
    dob.month = 0;
    dob.year = 0;
    today.day = 0;
    today.month = 0;
    today.year = 0;
    printf("Enter today's date\n");
    printf("Enter day = ");
    scanf("%d", &today.day);
    printf("Enter month number = ");
    scanf("%d", &today.month);
    printf("Enter full year = ");
    scanf("%d", &today.year);
    printf("\n");
    printf("Enter your date of birth\n");
    printf("Enter day = ");
    scanf("%d", &dob.day);
    printf("Enter month number = ");
    scanf("%d", &dob.month);
    printf("Enter full year = ");
    scanf("%d", &dob.year);

    Age = calculateAge(dob, today);
    printf("\nYou are %d years %d months and %d days old\n", Age.year, Age.month, Age.day);

    // DryRun
    //  5 7 '24
    //  25 8 '4

    // year -enteredY
    //  month<enteredM ? month+12-enteredM , remainingY -=1;
    // day<enteredDay ? day+30 - enteredDay , remainingM -=1;
    // currentMonth days =31 ? 31 : 30
}