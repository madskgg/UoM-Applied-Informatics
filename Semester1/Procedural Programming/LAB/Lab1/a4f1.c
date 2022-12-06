#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main()
{
 int rate;
 long purchaseAmount;
 double profit, saleAmount;

 printf("Dose kathari axia: ");
 purchaseAmount = GetLong();
 printf("Dose pososto kerdous: ");
 rate = GetInteger();
 profit = purchaseAmount*( (double) rate / 100);
 saleAmount = purchaseAmount+profit;
 printf("Kerdos: %g \nSynoliko poso: %g" , profit, saleAmount);
 return 0;
}
