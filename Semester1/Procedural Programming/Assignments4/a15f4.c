#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define US_DOLLAR_RATE 0.89
#define UK_POUND_RATE 0.618
#define SWISS_FRANC_RATE 1.5465
#define CANADIAN_DOLLAR_RATE 1.3565
#define YEN_RATE 109.22

int menu();
double conv(int option, double euro);

int main()
{
    int option=0;
    double euro;

    while (option!=6)
    {

        option = menu();
        if (option==6)
            break;

        printf("Dwse poso se euro: ");
        euro=GetReal();

        printf("%.2lf\n", conv(option, euro));
    }

    return 0;
}

int menu()
{
    //Στο φυλλάδιο αναφέρεται πως το μενού να μην εμφανίζεται σε μια printf
    printf("1. Metatroph se dollaria\n");
    printf("2. Metatroph se lires\n");
    printf("3. Metatroph se fraga Elbetias\n");
    printf("4. Metatroph se dollaria Canada\n");
    printf("5. Metatroph se gien\n");
    printf("6. Exodos\n");

    return GetInteger();
}

double conv(int x, double euro)
{
    double value;

    if (x==1)
        value = euro/US_DOLLAR_RATE;
    else if (x==2)
        value = euro/UK_POUND_RATE;
    else if (x==3)
        value = euro/SWISS_FRANC_RATE;
    else if (x==4)
        value = euro/CANADIAN_DOLLAR_RATE;
    else if (x==5)
        value = euro/YEN_RATE;

    return value;
}
