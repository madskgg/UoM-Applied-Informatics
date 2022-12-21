#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpio.h"

int FindDigitNums(int num);

int main()
{
    int num, L, digitNum, i;
    num = GetInteger();
    L = GetInteger();

    char tab[L+1];
    digitNum = FindDigitNums(num);

    char numStr[digitNum+1];
    itoa(num, numStr, 10);

    if (digitNum<L)
    {
        i=0;
        while (i<(L-digitNum))
        {
            tab[i]='0';
            i++;
        }
        tab[i]='\0';

        strcat(tab, numStr);
        printf("%s", tab);
    }
    else
        printf("%s", numStr);

    return 0;
}

int FindDigitNums(int num)
{
    int count=0;

    do
    {
        num /= 10;
        count++;
    }
    while (num != 0);

    return count;
}
