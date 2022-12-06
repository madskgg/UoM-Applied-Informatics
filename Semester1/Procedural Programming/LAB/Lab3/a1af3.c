#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "math.h"

#define CARS 80000
#define RATE 0.07
#define LIMIT 160000

int main()
{
    long c_cars;
    long years;

    c_cars = CARS;
    years = 0;

    while (c_cars <= LIMIT) {
        c_cars = ceil(c_cars * (1 + RATE));
        years++;
    }

    printf("%ld\n%ld", years, c_cars);

    return 0;
}
