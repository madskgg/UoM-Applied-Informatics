#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 10

void populate_data(int row, int col, int tab[row][col]);
void print_array(int row, int col, int tab[row][col]);
void change_array(int row, int col, int tab[row][col]);

int main()
{
    int tab[CTS][S];
    int i, j, R, C;

	printf("Dwse ton arithmo twn grammwn: ");
	R=GetInteger();
	printf("Dwse ton arithmo twn sthlwn: ");
	C=GetInteger();

	populate_data(R,C,tab);

   	printf("ARXIKOS PINAKAS\n");
    print_array(R,C,tab);

   	change_array(R,C,tab);

   	printf("ALLAGMENOS PINAKAS\n");
   	print_array(R,C,tab);

    return 0;
}

void populate_data(int row, int col, int tab[row][col])
{
    int i, j;

    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            tab[i][j] = rand()%100;
        }
    }
}

void print_array(int row, int col, int tab[row][col])
{
    int i, j;

    for (i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%2d ",tab[i][j]);
        }
        printf("\n");
    }
}

void change_array(int row, int col, int tab[row][col])
{
    int i, j, max, k;

    for (i=0; i<row; i++)
    {
        max = tab[i][0];
        k=0;
        for (j=1; j<col; j++)
        {
            if (tab[i][j]>max)
            {
                max = tab[i][j];
                k=j;
            }
        }
        for (j=0; j<k; j++)
        {
            tab[i][j] = max;
        }
    }
}
