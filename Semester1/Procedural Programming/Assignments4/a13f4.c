#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int Fibonacci(int N);

int main()
{
    int i,N;

    printf("Dwse to n: ");
    N = GetInteger();

    for (i=0; i<N; i++)
    {
        printf("%5d\n", Fibonacci(i));
    }


    return 0;
}

int Fibonacci(int N)
{
    if (N<2)
        return N;
    else
        return ( Fibonacci(N-1) + Fibonacci(N-2) );
}
