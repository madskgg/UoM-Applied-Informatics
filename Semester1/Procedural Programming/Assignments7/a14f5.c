#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 50

int readN();
void readData(int size, long a[]);
void printData(int size, long a[]);
int FindMaxsPos(int size, long a[], int index[]);


int main()
{
    long a[CTS];
    int i, size, index[CTS], maxCount;

    size = readN();
    readData(size, a);
    printData(size, a);
    maxCount = FindMaxsPos(size, a, index);
    printf("\nPlithos maximum %d\n", maxCount);

    printf("Positions of maximum ");
    for (i=0; i<size; i++)
    {
        if (index[i]!=-1)
        printf("%d ", index[i]);
    }


    return 0;

}

int readN()
{
    int N;

    printf("Dwse to plhthos twn stoixeiwn: ");
    N=GetInteger();

    return N;
}

void readData(int size, long a[])
{
    int i;

    for (i=0; i<size; i++)
    {
        a[i]=GetLong();
    }
}

void printData(int size, long a[])
{
    int i;

    for (i=0; i<size; i++)
    {
        printf("%ld ", a[i]);
    }
}

int FindMaxsPos(int size, long a[], int index[])
{
    int i,j, maxCount;
    long max;


    max = a[0];
    maxCount = 1;
    j=0;
    index[0] = 0;


    for (i=1; i<size; i++)
    {
        index[i]=-1;
        if (max<=a[i])
        {
            if (max==a[i])
            {
               j+=1;
               maxCount += 1;
               index[j]=i;
            }
            else
            {
                max = a[i];
                j = 0;
                maxCount = 1;
                index[j]=i;
            }

        }
    }
    printf("\nmaximum %ld", max);

    return maxCount;
}
