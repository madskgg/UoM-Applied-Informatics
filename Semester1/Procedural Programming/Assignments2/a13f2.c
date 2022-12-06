#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main()
{
    int coffee, resta, total, balance;

    printf("Dose kafedes:");
    coffee = GetInteger();
    total = coffee*70;
    if (total>500)
        printf("Sfalma");
    else
    {
        printf("Resta\n");
        resta = 500-total;
        balance = resta/200;
        printf("Kermata 2E :%d\n", balance);
        resta = resta%200;
        balance = resta/100;
        printf("Kermata 1E :%d\n", balance);
        resta = resta%100;
        balance = resta/50;
        printf("Kermata 50L :%d\n", balance);
        resta = resta%50;
        balance = resta/20;
        printf("Kermata 20L :%d\n", balance);
        resta = resta%20;
        balance = resta/10;
        printf("Kermata 10L :%d\n", balance);
    }

    return 0;
}
