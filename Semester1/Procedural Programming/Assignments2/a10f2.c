#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main()
{
    int code, pagio;
    long presentcounter, pastcounter, price, powerconsumption;
    double fpa, total;

    printf("Dwse ton kwdiko kathgorias timologiou: ");
    code = GetInteger();
    printf("Dwse thn parousa endeixh toy metrhth: ");
    presentcounter = GetLong();
    printf("Dwse thn prohgoumenh endeixh toy metrhth: ");
    pastcounter = GetLong();
    powerconsumption = presentcounter - pastcounter;

    if (powerconsumption<=200)
        price = powerconsumption*12;
    else if (powerconsumption<=500)
        price = 200*12 + (powerconsumption-200)*15;
    else if (powerconsumption<=1500)
        price = 200*12 + 300*15 + (powerconsumption-500)*20;
    else
        price = 200*12 + 300*15 + 1000*20 + (powerconsumption-1500)*30;

    if (code==1 || code==2)
        pagio = 20;
    else
        pagio = 100;

    fpa = ((double)18/100)*((price/100)+pagio);

    total = (price/100) + pagio + fpa;

    printf("Katanalwsh reumatos se monades: %ld\n", powerconsumption);
    printf("Axia reumatos (cent): %ld\n", price);
    printf("Pagio (eyro): %d\n", pagio);
    printf("FPA (euro): %g\n", fpa);
    printf("Synoliko poso plhrwmhs (euro): %g\n", total);

    return 0;
}
