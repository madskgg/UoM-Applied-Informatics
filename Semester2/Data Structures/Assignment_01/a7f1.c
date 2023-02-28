#include <stdio.h>
#include <stdlib.h>
#define megisto_plithos 5
#define PS_N 32  //2^5

typedef enum
{
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void createPowerSet(typos_synolou powersets[]);
void displayset(typos_synolou powersets[]);

int main()
{
    typos_synolou powersets[PS_N];
    createPowerSet(powersets);
    displayset(powersets);

    system("PAUSE");
    return 0;
}

void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}

void createPowerSet(typos_synolou powersets[])
{
    stoixeio_synolou i,j,k;
    for (i = 0; i < PS_N; i++)
    {
        k = i;
        Dimiourgia(powersets[i]);
        for (j = 0; j < megisto_plithos; j++)
        {
            if (k % 2)
                Eisagogi(j, powersets[i]);
            k >>= 1;
        }
    }
}

void displayset(typos_synolou powersets[])
{
    stoixeio_synolou i,j;

    printf("TO DYNAMOSYNOLO GIA N=%d\n", megisto_plithos);
    for (i = 0; i < PS_N; i++)
    {
        for (j = 0; j < megisto_plithos; j++)
            if (Melos(j, powersets[i]))
                printf("%d ", j + 1);
        printf("\n");
    }
}
