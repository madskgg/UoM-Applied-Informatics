#include <stdio.h>
#include "simpio.h"

#define N 20

typedef struct
{
    int code;
    char surname[16];
    long total_sales;
    int area;
} infoT;

void readData(int num, infoT sellers[]);
void calculateTotal(int num, infoT sellers[], long total[]);
void printData(long total[]);

int main()
{
    int num;
    long total[4]={0,0,0,0};
    infoT sellers[N];

    printf("Dwse to plhthos twn pwlhtwn? ");
    num = GetInteger();
    readData(num, sellers);
    calculateTotal(num, sellers, total);
    printData(total);
    return 0;
}


void readData(int num, infoT sellers[])
{
    int i;

    for (i=0;i<num;i++)
    {
        printf("Kwdikos? ");
        sellers[i].code = GetInteger();
        printf("Onomatepwnymo? ");
        gets(sellers[i].surname);
        printf("Poso pwlhsewn? ");
        sellers[i].total_sales = GetLong();
        printf("Kwdikos (1= Thes/niki, 2= Athens, 3= Volos, 4= Hrakleio)? ");
        sellers[i].area = GetInteger();
    }
}

void calculateTotal(int num, infoT sellers[], long total[])
{
    int i;

    for (i=0;i<num;i++)
    {
        if (sellers[i].area == 1)
            total[0]+= sellers[i].total_sales;
        else if (sellers[i].area == 2)
            total[1]+= sellers[i].total_sales;
        else if (sellers[i].area == 3)
            total[2]+= sellers[i].total_sales;
        else
            total[3]+= sellers[i].total_sales;
    }
}

void printData(long total[])
{
  int i;
    
  printf("%11s %12s", "PERIOXH", "SYN.PWLHSEWN\n");

  for (i=0; i<24; i++) printf("-");

  printf("\n%11s %12ld\n", "Thes/niki" ,total[0]);
  printf("%11s %12ld\n", "Athens", total[1]);
  printf("%11s %12ld\n", "Volos", total[2]);
  printf("%11s %12ld\n", "Hrakleio", total[3]);

  for (i=0; i<24; i++) printf("-");

  printf("\n%11s %12ld", "SYNOLO:", total[0]+total[1]+total[2]+total[3]);
}
