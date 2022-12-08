#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

void decompose(int N, int *digits, double *average, int *max);

int main()
{
    long N;
    int digits,max;
    double average;

    printf("Please insert non-negative number:");
    N = GetLong();

    decompose(N, &digits, &average, &max);

    printf("Digits: %d\n", digits);

    if (digits!=0)
	printf("Average: %.3f\n", average);

	printf("Max: %d", max);


    return 0;
}

void decompose(int N, int *digits, double *average, int *max)
{
    int sum=0;
    *max = 0;
    *digits = 0;

    while (N!=0)
    {
        *digits+=1;
        sum += N%10;
        if (N%10>*max)
        {
            *max = N%10;
        }

        N/=10;
    }

    if (*digits!=0)
        *average = (double)sum / *digits;

}
