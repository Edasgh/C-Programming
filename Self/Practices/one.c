#include <stdio.h>
// gcc one.c -o a
//.\a.exe

// write a program to check if three points (x1,y1) , (x2,y2) and (x3,y3) are collinear or not
int isCollinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int a = x1 * (y2 - y3) +
            x2 * (y3 - y1) +
            x3 * (y1 - y2);

    if (a == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    printf("Enter three points in (x,y) format to check if three of them are collinear or not\n");
    printf("Enter x1 = ");
    scanf("%d", &x1);
    printf("\nEnter y1 = ");
    scanf("%d", &y1);
    printf("\nEnter x2 = ");
    scanf("%d", &x2);
    printf("\nEnter y2 = ");
    scanf("%d", &y2);
    printf("\nEnter x3 = ");
    scanf("%d", &x3);
    printf("\nEnter y3 = ");
    scanf("%d", &y3);

    int collinear;

    collinear = isCollinear(x1, y1, x2, y2, x3, y3);

    if (collinear)
    {
        printf("\nThe three points (%d,%d) , (%d,%d) and (%d,%d) are collinear\n", x1, y1, x2, y2, x3, y3);
    }
    else
    {
        printf("\nThe three points (%d,%d) , (%d,%d) and (%d,%d) are not collinear\n", x1, y1, x2, y2, x3, y3);
    }
}
/*
INPUT : Enter three points in (x,y) format to check if three of them are collinear or not
Enter x1 = 1

Enter y1 = 1
Enter x1 = 1

Enter y1 = 1

Enter y1 = 1

Enter x2 = 1
Enter y1 = 1

Enter x2 = 1

Enter x2 = 1


Enter y2 = 4

Enter x3 = 1

Enter y3 = 5

OUTPUT :  The three points (1,1) , (1,4) and (1,5) are collinear
*/

/*
INPUT : Enter three points in (x,y) format to check if three of them are collinear or not
Enter x1 = 1

Enter y1 = 2

Enter x2 = 7

Enter y2 = 8

Enter x3 = 2

Enter y3 = 7

OUTPUT : The three points (1,2) , (7,8) and (2,7) are not collinear

*/