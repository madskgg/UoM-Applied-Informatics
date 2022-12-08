#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define ROW 30
#define COL 10

double sum(int i, int N, double grades[][COL]);

int main()
{
    int M,N,i,j;
    double grades[30][10], average[30];

    printf("Dwse ton arithmo twn mathitwn: ");
    M = GetInteger();
    printf("Dwse ton arithmo twn thematwn: ");
    N = GetInteger();

    for (i=1; i<=M; i++)
    {
        for (j=1; j<=N; j++)
        {
            printf("Dwse th bathmologia tou %dou thematos tou %dou mathiti: ", j, i);
            grades[i-1][j-1] = GetReal();
        }
    }

    for (i=0; i<M; i++)
        average[i] = sum(i, N, grades)/N;

    for (i=0; i<M; i++)
    {
        for (j=0; j<N; j++)
        {
            printf("%6.1lf", grades[i][j]);
            if (j==N-1)
                printf("%6.1lf\n", average[i]);
        }
        for (j=0; j<N; j++)
        {
            printf("%6.1lf", grades[i][j]/5);
            if (j==N-1)
                printf("%6.1lf\n", average[i]/5);
        }
    }

    return 0;
}

double sum(int i, int N, double grades[][COL])
{
    int j, ss=0;

    for (j=0; j<N; j++)
    {
        ss+=grades[i][j];
    }
    return ss;
}

