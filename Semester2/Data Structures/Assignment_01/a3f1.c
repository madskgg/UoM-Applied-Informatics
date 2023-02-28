#include <stdio.h>
#include <stdlib.h>

#define megisto_plithos 26

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Katholiko(typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);
void EmfanisiSynolou(typos_synolou set);

int main()
{
    typos_synolou set, set1, set2, enosi, tomi, diafora;

    Dimiourgia(set);
    Katholiko(set);
    EmfanisiSynolou(set);

    Dimiourgia(set1);
    for (int i=0; i<=3; i++)
       Eisagogi(i,set1);

    Dimiourgia(set2);
    for (int i=0; i<=8; i=i+2)
       Eisagogi(i,set2);

    EmfanisiSynolou(set1);
    EmfanisiSynolou(set2);

    if (IsaSynola(set1,set2))
        printf("ISA SYNOLA\n");
    else
        printf("NOT ISA SYNOLA\n");

    if (Yposynolo(set1,set2))
      	printf("S YPOSYNOLO T'\n");
    else
        printf("NOT S YPOSYNOLO T\n");

    if (Yposynolo(set2,set1))
      	printf("T YPOSYNOLO S'\n");
    else
        printf("NOT T YPOSYNOLO S\n");

    EnosiSynolou(set1,set2,enosi);
    EmfanisiSynolou(enosi);

    TomiSynolou(set1,set2,tomi);
    EmfanisiSynolou(tomi);
    DiaforaSynolou(set1,set2,diafora);
    EmfanisiSynolou(diafora);


    return 0;
}

void Katholiko(typos_synolou synolo)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
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

boolean IsaSynola(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)
{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}

void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        enosi[i] = Melos(i, s1) || Melos(i, s2);
}

void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        tomi[i] = Melos(i, s1) && Melos(i, s2);
}

void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora)
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        diafora[i] = Melos(i, s1) && (!Melos(i, s2));
}

void EmfanisiSynolou(typos_synolou set)
{
    stoixeio_synolou i;

    for (i=0; i < megisto_plithos; i++)
    {
        if(Melos(i,set))
            printf(" %c", 'A' + i);
    }
    printf("\n");
}

