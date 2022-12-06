#include <stdio.h>
#include <stdlib.h>

#define LENGTH 30
#define COL 2
#define HOURSGAP 6

void ReadData(int row, char bands[][LENGTH], double hours[][COL]);
void Frequency(int size, double hours[][COL], int perfTime[]);
void PrintData(int size, double hours[][COL], int perfTime[], char bands[][LENGTH], int max, int maxpos);
void findMAX(int perfTime[], int *max, int *maxpos);

int main()
{
    int size, max, maxpos;

    printf("Dwse arithmo bands: ");
    scanf("%d", &size);

    char bands[size][LENGTH];
    double hours[size][COL];
    int perfTime[HOURSGAP]= {0,0,0,0,0,0};;

    ReadData(size, bands, hours);
    Frequency(size, hours, perfTime);
    findMAX(perfTime, &max, &maxpos);
    PrintData(size, hours, perfTime, bands, max, maxpos);

    printf("\n");
    system("PAUSE");
    return 0;
}

void ReadData(int size, char bands[][LENGTH], double hours[][COL])
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Dwse to onoma tou band: ");
        scanf(" %[^\n]s", bands[i]);

        printf("Dwse wra afiksis(18.00 - 24.00): ");
        scanf("%lf", &hours[i][0]);

        printf("Dwse wra anaxwrisis(18.00 - 24.00): ");
        scanf("%lf", &hours[i][1]);

        fflush(stdin);

    }
}

void Frequency(int size, double hours[][COL], int perfTime[])
{
    int i,j;

    for (i = 0; i < HOURSGAP; i++)
    {
        for (j=0; j<size; j++)
        {
            if (hours[j][0]<=i+18 && hours[j][1]>i+18)
                perfTime[i]++;
        }
    }
}


void PrintData(int size, double hours[][COL], int perfTime[], char bands[][LENGTH], int max, int maxpos)
{
    int i;

    for (i=0; i<HOURSGAP; i++)
    {
        if (max==perfTime[i])
        {
            printf("Apo tis %.2lf ews tis %.2lf emfanizontai oi perissoteres diasimotites kai sigkekrimena:\n", (double)maxpos+18, (double)maxpos+19);
            printf("---------------------------------------------------------------------------------------\n");
            break;
        }
    }
    for (i=0; i<size; i++)
    {
        if (hours[i][0]<= maxpos+18 && hours[i][1]>maxpos+18)
            printf("%s\n", bands[i]);
    }
}

void findMAX(int perfTime[], int *max, int *maxpos)
{
    *max = perfTime[0];
    *maxpos = 0;

    for (int i=1; i<HOURSGAP; i++)
    {
        if (perfTime[i]>*max)
        {
            *max = perfTime[i];
            *maxpos = i;
        }
    }
}
