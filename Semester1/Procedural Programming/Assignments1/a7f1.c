#include <stdio.h>
#include "simpio.h"
int main()
{
    long tax1, tax2, tax3;
    double fpa;

    printf("Dwse tis synolikes eispraxeis gia FPA 0.04: ");
    tax1 = GetLong();
    printf("Dwse tis synolikes eispraxeis gia FPA 0.08: ");
    tax2 = GetLong();
    printf("Dwse tis synolikes eispraxeis gia FPA 0.18: ");
    tax3 = GetLong();
    fpa = (tax1*0.04)+(tax2*0.08)+(tax3*0.18);
    printf("To synoliko poso FPA einai %g", fpa);
    return 0;
}
