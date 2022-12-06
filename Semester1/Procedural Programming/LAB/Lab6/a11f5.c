#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 3

int main()
{
    int i,j;
    double temper[CTS][S], natavg, average[CTS], devnat[CTS][S], max[CTS];

    natavg=0;

    //INPUT
    for (i=0; i<CTS; i++)
    {
        for (j=0; j<S; j++)
        {
            printf("Temp of City %d During %d 8-hour period: ", i, j);
            temper[i][j]=GetReal();
        }

    }

    //CALCULATION
    for (i=0; i<CTS; i++)
    {
        for (j=0; j<S; j++)
        {
            natavg += temper[i][j];
        }

    }

    natavg /= (CTS*S);

    for (i=0; i<CTS; i++)
    {
        average[i]=0;

        for (j=0; j<S; j++)
        {
            average[i] += temper[i][j];
        }

        average[i] /= S;
    }

    for (i=0; i<CTS; i++)
    {

        for (j=0; j<S; j++)
        {
            devnat[i][j]=fabs(natavg-temper[i][j]);
        }
    }

    for (i=0; i<CTS; i++)
    {
        max[i]=devnat[i][0];
        for (j=1; j<S; j++)
        {
            if (max[i]<devnat[i][j])
                max[i] = devnat[i][j];
        }
    }

    //OUTPUT
    printf("%.1f\n", natavg);

    for (i=0; i<CTS; i++)
        printf("City %d %.1f %.1f\n", i, average[i], max[i]);

    return 0;
}
