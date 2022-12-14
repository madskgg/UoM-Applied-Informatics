#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define S 100

int readData(int size, int tab[]);
void findMinMax(int count, int tab[], int *max, int *min);

int main()
{
    int tab[S], count, max, min;

    printf("Enter the elements of the array, one per line.\n");
    printf("Use -1 to signal the end of the list.\n");
    count = readData(S, tab);

    findMinMax(count, tab, &max, &min);
    printf("The range of values is %d-%d",min,max);

    return 0;
}

int readData(int size, int tab[])
{
    int number,i;

    for(i=0; i<size; i++)
    {
        printf("? ");
        number=GetInteger();
        if(number==-1)
            break;
        else
            tab[i]=number;
    }
    return i;
}


void findMinMax(int count, int tab[], int *max, int *min)
{
    int i;
    *max = tab[0];
    *min = tab[0];
    for(i=1; i<count; i++)
    {
        if (tab[i] > *max)
            *max = tab[i];
        if (tab[i] < *min)
            *min = tab[i];
    }
}
