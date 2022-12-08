#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define N 5
#define S 4
#define G 2

void ReadData(int row, int col, int personData[row][col]);
void FindMean(int row, int indicator, int personData[row][S], double average[G][3]);

int main()
{
    int personData[N][S];
    double average[G][3];

    ReadData(N, S, personData);

    FindMean(N, 1, personData, average);
    printf("Mesos oros barous andrwn: %.1f\n",average[0][0]);
    printf("Mesos oros barous gynaikwn: %.1f\n",average[1][0]);
    printf("\n");

    FindMean(N, 2, personData, average);
    printf("Mesos oros ypsous andrwn: %.1f\n",average[0][1]);
    printf("Mesos oros ypsous gynaikwn: %.1f\n",average[1][1]);
    printf("\n");

    FindMean(N, 3, personData, average);
    printf("Mesos oros hlikias andrwn: %.1f\n",average[0][2]);
    printf("Mesos oros hlikias gynaikwn: %.1f\n",average[1][2]);

    return 0;
}

void ReadData(int row, int col, int personData[row][col])
{
    int i,j;

    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            if (j==0)
            {
                printf("Dwse fylo: ");
            }
            else if (j==1)
            {
                printf("Dwse baros: ");
            }
            else if (j==2)
            {
                printf("Dwse ypsos: ");
            }
            else
            {
                printf("Dwse ilikia: ");
            }
            personData[i][j] = GetInteger();
        }
        printf("-----\n");
    }
}

void FindMean(int row, int indicator, int personData[row][S], double average[G][3])
{

 int i, men=0, women=0, sum1=0, sum2=0;

 for (i=0; i<row; i++)
 {
     if (personData[i][0] == 0)
     {
         men += 1;
         sum1 += personData[i][indicator];
     }
     else
     {
         women += 1;
         sum2 += personData[i][indicator];
     }
 }

 if (men!=0)
    average[0][indicator-1]=(double)sum1/men;
 else
    average[0][indicator-1]=0;

 if (women!=0)
    average[1][indicator-1]=(double)sum2/women;
 else
    average[0][indicator-1]=0;
}
