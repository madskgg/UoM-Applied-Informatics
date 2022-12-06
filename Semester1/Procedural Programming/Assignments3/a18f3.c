#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{

    int total, people, max, min, amount;

    total = people = 0;

    max = -1;

    while (total<100000)
    {
        printf("Dwse poso: ");
        amount = GetInteger();

        total += amount;
        people += 1;

        if (people == 1)
            min = amount;

        if (max<amount)
            max = amount;

        if (min>amount)
            min = amount;
    }

    printf("Plithos atomwn: %d\n", people);
    printf("Synoliko poso: %d\n", total);
    printf("Megalytero poso: %d Mikrotero poso: %d", max, min);

    return 0;
}
