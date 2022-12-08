#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main()
{
    long taxsprc[10] = {0, 18, 21, 24, 28, 33, 38, 43, 49, 50};
    long salaries[10] = {0, 10000, 39000, 49000, 59000, 85000, 100000, 120000, 150000, 170000};
    long maxScaleTax[10] = {0, 0, 5220, 7320, 9720, 17000, 21950, 29550, 42450, 52250};
    long yearlyIncome, rem, remprc, total;
    int i, temp;


    printf("Dwse to eisodhma: ");
    yearlyIncome = GetLong();

    for (i=0; i<10; i++)
    {
        if (yearlyIncome<=salaries[i])
        {
           temp=i-1;
           rem = yearlyIncome-salaries[temp];
           remprc = rem*taxsprc[temp]/100;
           total = maxScaleTax[temp]+remprc;
           break;
        }
        else if (yearlyIncome>170000)
        {
           temp=9;
           rem = yearlyIncome-salaries[temp];
           remprc = rem*taxsprc[temp]/100;
           total = maxScaleTax[temp]+remprc;
           break;
        }
    }

    printf("%ld Euro\n", yearlyIncome);
    printf("%ld Euro\n", maxScaleTax[temp]);
    printf("%ld Euro\n", remprc);
    printf("%ld Euro\n", total);

    return 0;

}
