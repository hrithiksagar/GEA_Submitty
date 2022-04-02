#include "complex.h"
#include "compute.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


complex_t complex_sum(complex_t a,complex_t b)
{
    complex_t sum;
    sum.real = a.real + b.real;
    sum.img = a.img + b.img;
    return sum;
    }

    complex_t complex_difference(complex_t a,complex_t b)
{
    complex_t diff;
    diff.real = a.real - b.real;
    diff.img = a.img - b.img;
    return diff;
    }

    complex_t complex_multiply(complex_t a,complex_t b)
{
    complex_t mul;
    mul.real = ((a.real*b.real)-(a.img*b.img));
    mul.img = ((a.real*b.img)+(b.real*a.img));
    return mul;
    }

    complex_t complex_divide(complex_t a,complex_t b)
{
    complex_t div;
    if(b.real == 0 && b.img == 0)
    {
        div.real=0;
        div.img=0;
        return (div);
    }
    else
    {
        div.real=((a.real*b.real+a.img*b.img)/(b.real*b.real+b.img*b.img));
        div.img=((a.img*b.real-a.real*b.img)/(b.real*b.real+b.img*b.img));
        return (div);
    }
}
   
