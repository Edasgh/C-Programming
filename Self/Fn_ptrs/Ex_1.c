#include <stdio.h>
#include <math.h>
// gcc Ex_1.c -o a
//.\a.exe

// area of a circle where the radius = eucledian distance of two points
float eucledianDistance(int x1, int y1, int x2, int y2)
{
    float distance;
    float xd, yd, sqxd, sqyd;
    xd = (float)(x2 - x1);
    yd = (float)(y2 - y1);
    sqxd = powf(xd, 2.00);
    sqyd = powf(yd, 2.00);
    distance = sqrtf((sqxd + sqyd));

    return distance;
}

float areaOfCircle(int x1, int y1, int x2, int y2, float (*fptr)(int, int, int, int))
{
    float radius = fptr(x1, y1, x2, y2);
    float PI = 3.14;
    float area;
    area = PI * powf(radius, 2.00);
    return area;
}

void main()
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    float area;
    printf("Enter two points here to get area of circle :  points will be in (x,y) format \n");
    printf("Enter the first point\n");
    printf("x =");
    scanf("%d", &x1);
    printf("\ny=");
    scanf("%d", &y1);
    printf("\nNow ,enter the second point\n");
    printf("x =");
    scanf("%d", &x2);
    printf("\ny=");
    scanf("%d", &y2);

    float (*ptr)(int, int, int, int);
    ptr = &eucledianDistance;

    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
    {
        printf("The given points dosen't lie on a circle!\n");
    }
    else
    {

        area = areaOfCircle(x1, y1, x2, y2, ptr);
        printf("The area of the circle passing through the points , (%d,%d) & (%d,%d) is %.2f\n", x1, y1, x2, y2, area);
    }
}