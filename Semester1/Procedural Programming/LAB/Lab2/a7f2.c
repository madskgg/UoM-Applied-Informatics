#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main()
{
    int hours;
    long code;
    double salary, weekly_amount, wage;

    printf("Dwse ton kwdiko:");
    code = GetLong();
    if (code>=1000)
    {
        printf("Dwse ton ethsio mistho:");
        salary = GetReal();
        weekly_amount = salary/52;
    }
    else
    {
        printf("Dwse tis wres ebdomadiaias ergasias:");
        hours = GetInteger();
        printf("Dwse thn amoibh ana wra:");
        wage = GetReal();
        if (hours<=40)
            weekly_amount = hours*wage;
        else
            weekly_amount = 40*wage + (hours-40)*wage*1.5;
    }
    printf("H ebdomadiaia amoibh einai %g\n", weekly_amount);
    return 0;
}
