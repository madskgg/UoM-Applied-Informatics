#include <stdio.h>
#include "simpio.h"
int main()
{
    int workdays;
    long dailywage;
    double giftpercentage, gift;

    printf("Dwse tis hmeres ergasias tou etous: ");
    workdays = GetInteger();
    printf("Dwse thn hmerhsia amoibh: ");
    dailywage = GetLong();
    printf("Dwse to pososto dwroy: ");
    giftpercentage = GetReal();
    gift = workdays*dailywage*giftpercentage;
    printf("To dwro einai %g", gift);
    return 0;
}
