#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 2nd order
// k1 = h*fd(x1,y1)
// k2= h*fd(x1+h,y1+k1)
// k = 1/2 * (k1+k2)

// 4th order
//  k1=h*fd(x1,y1)
//  k2=h*fd(x1+h/2,y1+k1/2)
//  k3=h*fd(x1+h/2,y1+k2/2)
//  k4=h*fd(x1+h,y1+k3)
//  k = 1/6 * (k1+2l2+2k3+k4)

// x = xn-1 + h
// y = yn-1 + k