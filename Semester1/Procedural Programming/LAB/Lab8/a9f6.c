#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define SALESMEN 4
#define PRODUCTS 5

void calculateSales(int row, int col, int price[], int sales[][col], int salesPerson[]);

void calculateProductSales(int row, int col, int sales[row][col], int productSale[]);
void printArray(int row, int tab[]);
void maxArray(int size, int tab[], int *max, int *maxpos);

int main()
{
    int price[] = {250, 150, 320, 210, 920};
    int sales[SALESMEN][PRODUCTS]=
    {
        {10,4,5,6,7},
        {7,0,12,1,3},
        {4,19,5,0,8},
        {3,2,1,5,6}
    };
    int salesPerson[SALESMEN], productSale[PRODUCTS];
    int bestsalesperson, income, bestProduct, items;

    calculateSales(SALESMEN, PRODUCTS, price, sales, salesPerson);
    printf("SalesMan-Sales\n");
    printArray(SALESMEN, salesPerson);

    maxArray(SALESMEN, salesPerson, &income, &bestsalesperson);
    printf("Best SalesMan was %d with %d sales\n", bestsalesperson, income);

    calculateProductSales(SALESMEN, PRODUCTS, sales, productSale);
    printf("Product-Items\n");
    printArray(PRODUCTS, productSale);

    maxArray(PRODUCTS, productSale, &items, &bestProduct);
    printf("Best Product was %d with %d items\n", bestProduct, items);

    return 0;
}

void calculateSales(int row, int col, int price[], int sales[row][col], int salesPerson[])
{
    for (int i=0; i<row; i++)
    {
        salesPerson[i]=0;
        for (int j=0; j<col; j++)
        {
            salesPerson[i]+=sales[i][j]*price[j];
        }
    }
}

void calculateProductSales(int row, int col, int sales[row][col], int productSale[])
{
    for (int i=0; i<col; i++)
    {
        productSale[i]=0;
        for (int j=0; j<row; j++)
        {
            productSale[i]+= sales[j][i];
        }
    }
}

void maxArray(int size, int tab[], int *max, int *maxpos)
{
    *max = tab[0];
    *maxpos=0;

    for (int i=1; i<size; i++)
    {
        if (tab[i]>*max)
        {
            *max = tab[i];
            *maxpos = i;
        }
    }
}

void printArray(int size, int tab[])
{
    for (int i=0; i<size; i++)
        printf("%4d     %d\n",i, tab[i]);
}

