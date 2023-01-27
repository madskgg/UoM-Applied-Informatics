#include <stdio.h>
#include <string.h>
#include "simpio.h"

#define N 100

typedef struct
{
    int num;
    char name[28];
    int points;
} playerT;

void readFromFile(FILE* infile, playerT players[], int* playerCount)
{
    int nscan, number, points;
    char name[28], termch;
    *playerCount = 0;

    while (TRUE)
    {
        nscan = fscanf(infile, "%d,%28[^,],%d%c", &number, name, &points, &termch);
        if (nscan == EOF) break;

        if (nscan!=4 || termch!='\n')
        {
            printf("Error in line %d. Program termination\n", playerCount);
            exit(1);
        }
        players[*playerCount].num = number;
        strcpy(players[*playerCount].name, name);
        players[*playerCount].points = points;
        (*playerCount)++;
    }
}

void writeToFile(FILE* outfile, playerT players[], int playerCount)
{
    int i, totalPoints = 0, overPoints = 0;

    fprintf(outfile, "%-28s %10s\n", "ONOMATEPWNYMO", "PONTOI");
    for (i=0; i<39; i++) fprintf(outfile, "-");
    fprintf(outfile, "\n");
    for (i = 0; i < playerCount; i++)
    {
        fprintf(outfile, "%-28s %10d\n", players[i].name, players[i].points);
        totalPoints += players[i].points;
        if (players[i].points > 10)
        {
            overPoints++;
        }
    }
    for (i=0; i<39; i++) fprintf(outfile, "-");
    fprintf(outfile, "\n");
    fprintf(outfile, "%-28s %10d\n", "SYNOLO PONTWN", totalPoints);
    fprintf(outfile, "%-28s %10d\n", "SYNOLO PAIKTWN >= 10", overPoints);
}

int main()
{
    int playerCount;
    playerT players[N];
    FILE *infile, *outfile;
    infile = fopen("i11f9.dat", "r");
    if (infile==NULL)
    {
        printf("Error: File not found");
        exit(1);
    }
    outfile = fopen("baso11f9.dat", "w");
    readFromFile(infile, players, &playerCount);
    writeToFile(outfile, players, playerCount);

    fclose(infile);
    fclose(outfile);
    return 0;
}
