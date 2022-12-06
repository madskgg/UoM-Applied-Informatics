#include <stdio.h>
#include <math.h>
#include "simpio.h"
#include "genlib.h"

int get_code();
double discount_percentage(int code);
int product_points(int code, double finalPrice);

int main()
{
    int code, points;
    double price, finalPrice, discount, total, discountSum;

    total = discountSum = 0;
    points = 0;

    /*input*/

    while (TRUE)
    {
        code=get_code();
        if (code==0)
            break;
        printf("Dwse thn timh: ");
        price = GetReal();

        /*computation*/
        discount = discount_percentage(code)*price;
        discountSum += discount;
        finalPrice = price-discount;
        total += finalPrice;
        points += product_points(code, finalPrice);
    }

    /*output*/
    printf("------------------\n");
    printf("Teliko synolo: %.2f Euro\n", total);
    printf("Ekptwsh: %.2f Euro\n", discountSum);
    printf("Pontoi: %d\n", points);

    return 0;
}

int get_code()
{
    int code;
    while (TRUE)
    {
        printf("Dwse ton kwdiko: ");
        code = GetInteger();

        if (code>=0 && code<=2000)
            return code;

        printf("Lathos Kwdikos (0-2000)\n");
    }
}

double discount_percentage(int code)
{
    if (code<=300)
        return 0.05;
    else if (code<=500)
        return 0.1;
    else if (code<=1000)
        return 0.15;
    else
        return 0.2;
}

int product_points(int code, double finalPrice)
{
    if (code>=1000 && code<=1500)
        return 1+ceil(finalPrice/5);

    return 1;
}
