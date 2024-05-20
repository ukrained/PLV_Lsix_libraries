#include <stdio.h>
#include "mymath.h"


int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

unsigned long long factorial(int a)
{
    int i = 0;
    unsigned long long fact = 1;

    for (i = 1; i <= a; i++) {
        fact = fact * i;
    }

    return fact;
}

float sqroot(int a)
{
    float sqrt, t;

    sqrt = a/2;
    t = 0;

    while (sqrt != t)
    {
        t = sqrt;
        sqrt = (a/t + t) / 2;
    }

    return sqrt;

}
