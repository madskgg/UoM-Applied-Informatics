#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main()
{
    int seats, passengers;
    double percent;
    printf("Dose theseis :");
    seats = GetInteger();
    printf("Dose epibates :");
    passengers = GetInteger();
    percent = ((double)passengers)/seats*100;
    if (percent<30)
        printf("Zimia");
    else if (percent<50)
        printf("Kostos");
    else
        printf("Kerdos");

    return 0;
}
