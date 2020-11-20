#ifndef HELPER
#define HELPER

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

int randomBoolean()
{
    return int((rand() % 100) > 50);
}

int randomNum(int lower, int upper)
{
    return (rand() % (upper-lower)) + lower;
}

void delay(float milli_seconds)
{
    clock_t start = clock();
    while(clock() - start < milli_seconds);
}

int toDecimal(int *array, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i])
        {
            sum += pow(2,n-i-1);
        }
    }
    return sum;
}

#endif