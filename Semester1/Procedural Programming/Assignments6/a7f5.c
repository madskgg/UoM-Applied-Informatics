#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


int main()
{
    int M1,N1,M2,N2, i,j, k;
    long table1[50][50], table2[50][50], sum[50][50], dif[50][50], mul[50][50];


    printf("Dwse to plhthos twn grammwn m1: ");
    M1=GetInteger();
    printf("Dwse to plhthos twn sthlwn n1: ");
    N1=GetInteger();
    printf("Dwse to plhthos twn grammwn m2: ");
    M2=GetInteger();
    printf("Dwse to plhthos twn sthlwn n2: ");
    N2=GetInteger();

    for (i=0; i<M1; i++)
    {
        for (j=0; j<N1; j++)
        {
            table1[i][j] = GetLong();
        }
    }

    for (i=0; i<M2; i++)
    {
        for (j=0; j<N2; j++)
        {
            table2[i][j] = GetLong();
        }
    }

    if (M1==M2 && N1==M2)
    {

        for (i=0; i<M1; i++)
        {

            for (j=0; j<N1; j++)
            {

                sum[i][j]=table1[i][j]+table2[i][j];
                dif[i][j]=table1[i][j]-table2[i][j];
            }
        }

        for (i=0; i<M1; i++)
        {
            for (j=0; j<N1; j++)
            {
                printf("%ld ", sum[i][j]);
            }
            printf("\n");
        }

        for (i=0; i<M1; i++)
        {
            for (j=0; j<N1; j++)
            {

                printf("%ld ", dif[i][j]);
            }
            printf("\n");
        }

    }
    else
    {
        printf("ERROR +\n");
        printf("ERROR -\n");
    }

    if (M2==N1)
    {

        for (i=0; i<M1; i++)
        {
            for (j=0; j<N2; j++)
                mul[i][j]=0;
        }
        for (i=0; i<M1; i++)
        {
            for (j=0; j<N2; j++)
            {
                for (k=0; k<N1; k++)
                    mul[i][j]+=table1[i][k]*table2[k][j];
            }
        }

        for (i=0; i<M1; i++)
        {
            for (j=0; j<N2; j++)
            {
                printf("%ld ", mul[i][j]);
            }
             printf("\n");
        }
    }
    else
        printf("ERROR *");


    return 0;

}
