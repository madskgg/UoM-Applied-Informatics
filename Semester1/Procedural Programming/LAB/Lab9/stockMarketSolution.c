#include <stdio.h>
#include "genlib.h"
#define LENGTH 11
#define R 5
#define C 10

float findMax(int size, float array[LENGTH]);
int findInterestingValues(int size, float max_t, float array[LENGTH], float interestingvalue[LENGTH]);
void printDataMax(int size, float max, float array[LENGTH]);
void printData(int ni, float array[LENGTH]);
void printDash(int size);
void valueCalculator(int risk[LENGTH], float cds_prices[LENGTH], float values[LENGTH]);
void high_low(int i, float deriv_day_data[][10], int *high, int *low);
bool element(float value, int row, int *pos, int r, int c, float table[r][c]);

int main()
{
    float stock_prices[10] = {34.5, 22.4, 77.8, 22.1, 10.0, 11.25, 12, 13, 16, 20.5 };
    float deriv_prices[5] = {30.5, 21.4, 89.8, 20.1, 10.0};
    float cds_prices[11] = {38.5, 33.4, 67.8, 12.1, 16.0, 10.25, 11, 23, 36, 10.1,30.4};
    int risk[11] = {90,10,20,30,50,60,30,30,30,10,10};

    float deriv_day_data[5][10] =
    {
        {30.5,25,22,32.3,30.5,32.6,38.9,40,22,30.5},
        {22.5,21.4,14,40.3,22.5,12.6,38.9,40,39,21.4},
        {30.5,25,22,89.8,34.5,89.8,38.9,40,30,89.8},
        {20.2,35,20.1,12.3,20.1,32.6,38.9,40,22,20.1},
        {45.5,10.0,22,10.0,14.5,23.6,48.9,8,10.0,10.0}
    };

    float interesting_stock[10];
    int ni_stock;
    float interesting_cds[11];
    int ni_cds;
    float values[11];
    float max_stock, max_deriv, max_cds;
    int i, high, low, pos;
    float value;

    //Calculate Max
    max_stock = findMax(10, stock_prices);
    max_deriv = findMax(5, deriv_prices);
    max_cds = findMax(11, cds_prices);

    //Calculate Interesting Values
    ni_stock = findInterestingValues(10, max_stock, stock_prices, interesting_stock);
    ni_cds = findInterestingValues(11, max_cds, cds_prices, interesting_cds);

    //Printing

    printf("Stock Prices.\n");
    printDash(30);
    printDataMax(10, max_stock, stock_prices);
    printf("Interesting Stock Prices:");
    printData(ni_stock, interesting_stock);
    printDash(10);
    printf("Derivative Prices.\n");
    printDash(30);
    printDataMax(5, max_deriv, deriv_prices);
    printDash(10);
    printf("CDS Prices.\n");
    printDash(30);
    printDataMax(11, max_cds, cds_prices);
    printf("Interesting CDS Prices:");
    printData(ni_cds, interesting_cds);
    printDash(30);

    valueCalculator(risk, cds_prices, values);
    printf("CDS assessment\n");
    for (i=0; i<LENGTH; i++)
        printf("CDS assessment: cds %.2f Risk %d Value %.2f\n", cds_prices[i], risk[i], values[i]);

     printDash(30);
    printf("Derivative Low High\n");
    for (i=0; i<R; i++)
    {
    high_low(i, deriv_day_data, &high, &low);
     printf("Devirative %d, high %d / low %d values.\n", i, high, low);

    }
     printDash(30);

     printf("Closing\n");
     for (i=0;i<R;i++)
     {
         pos = 0;
         value = deriv_day_data[i][9];
         printf("Devirative %d, closing value at :: ", i);
         while (pos<C)
         {
             if (element(value,i, &pos, R, C, deriv_day_data)) printf(" %d", pos);
             pos++;
         }
         printf("\n");
     }

    return 0;
}

float findMax(int size, float array[])
{
    int i;
    float max;

    max = array[0];
    for (i=1; i<size; i++)
    {
        if (array[i]>max)
            max = array[i];
    }

    return max;
}


int findInterestingValues(int size, float max_t, float array[], float interestingvalue[])
{
    int i, ni = 0;;

    for (i=0; i<size; i++)
    {
        if (array[i] > max_t / 2)
            interestingvalue[ni++] = array[i];
    }
    return ni;
}

void printDataMax(int size, float max, float array[])
{
    int i;

    printf("Max Price:: %4.2f \n",max);
    for(i=0; i<size; i++)
        printf("%s(%3.2f) ",(max == array[i] ? "-Max-" : ""),array[i]);
    printf("\n");


}

void printData(int ni, float array[])
{
    int i;

    for(i=0; i<ni; i++) printf("[%4.2f] ",array[i]);
    printf("\n");
}

void printDash(int size)
{
    int i;

    for (i=0; i<size; i++) printf("-");
    printf("\n");
}

void valueCalculator(int risk[], float cds_prices[], float values[])
{
    int i;

    for (i=0; i<11; i++)
    {
        if  (cds_prices[i]<20 && risk[i]<50)
            values[i] = 20;
        else if (cds_prices[i]>=20 && risk[i]<80)
            values[i] = 10+(cds_prices[i]*risk[i])/100;
        else
            values[i] = 100+(cds_prices[i]*risk[i])/100;
    }
}

void high_low(int i, float deriv_day_data[][10], int *high, int *low)
{
    int j;

    *high=0;
    *low=0;
    for (j=0; j<9; j++)
    {
        if (deriv_day_data[i][9]<deriv_day_data[i][j])
        {
            (*high)++;
        }
        else if (deriv_day_data[i][9]>deriv_day_data[i][j])
        {
            (*low)++;
        }
    }
}

bool element(float value, int row, int *pos, int r, int c, float table[r][c])
{
    if (value==table[row][*pos])
    {
        return TRUE;
    }
    return FALSE;
}
