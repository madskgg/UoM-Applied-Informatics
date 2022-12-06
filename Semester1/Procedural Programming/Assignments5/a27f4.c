#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

long encode(long N);
bool check(long EN);

int main()
{
    long N, EN, lowlimit, uplimit;

    printf("Lower Limit:");
    lowlimit = GetLong();
    printf("Upper Limit:");
    uplimit = GetLong();

    for (N=lowlimit; N<=uplimit; N++)
    {
        EN = encode(N);

        if (check(EN))
            printf("Code: %ld Encoding: %ld isValid:yes\n", N, EN);
        else
            printf("Code: %ld Encoding: %ld isValid:no\n", N, EN);

    }

    return 0;
}

long encode(long N)
{
    int digits;

    digits = (98 - (N*100) % 97) % 97;

    return N*100+digits;
}

bool check(long EN)
{
    if (EN%97==1)
        return TRUE;

    return FALSE;
}
