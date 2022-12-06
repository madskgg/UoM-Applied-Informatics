#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

bool Valid_Time(int hours, int mins, int secs);

int main()
{
    int hours, mins, secs;

    printf("Dwse tis ores: ");
    hours = GetInteger();
    printf("Dwse ta lepta: ");
    mins = GetInteger();
    printf("Dwse ta defterolepta: ");
    secs = GetInteger();

    if (Valid_Time(hours, mins, secs))
        printf("Valid: yes");
    else
        printf("Valid: no");

    return 0;
}

bool Valid_Time(int hours, int mins, int secs)
{
    if (hours>=0 && hours<=23 && mins>=0 && mins<=59 && secs>=0 && secs<=59)
        return TRUE;

    return FALSE;
}
