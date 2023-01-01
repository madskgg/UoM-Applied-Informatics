#include <stdio.h>
#include "genlib.h"

#define FRIENDS 15
#define LENGTH 15

void fillAray(int SIZE, int tab[], int NUM);
void secFill(int SIZE, int tab[], int start, int excludedPos[]);
void loop(int SIZE, int tab[], int size, int row, int col, char names[row][col], int disSize, int dislike[disSize][disSize]);
void combinations(int tab[], int currCombo[], int start, int end, int index, int size, int row, int col, char names[row][col], int disSize, int dislike[disSize][disSize]);

int main()
{
    char names[FRIENDS][LENGTH]= {"Nikos", "Lydia", "Marilia", "Giannis", "Manos", "Petros", "Akis", "Eleni", "Zwi", "Maria", "Dimitris", "Aleksandros", "Anna", "Artemis", "Alekos"};
    int dislike[FRIENDS][FRIENDS]=
    {
        {0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0},
        {1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	1,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0},
        {1,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	1,	1,	0,	0,	0,	1,	1,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0},
        {0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1},
        {0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0}
    };

    int akmes[FRIENDS], friendRemoved[FRIENDS], zeroEdgesPos[FRIENDS], zeroEdgesPosT[FRIENDS];
    int maxFriends, mostEdges, mostEdgesPos, flag, i, j;

    fillAray(FRIENDS, friendRemoved, 0);
    fillAray(FRIENDS, zeroEdgesPos, 0);
    fillAray(FRIENDS, zeroEdgesPosT, 0);

    maxFriends = 0;

    do
    {
        fillAray(FRIENDS, akmes, 0);
        mostEdges = mostEdgesPos = 0;
        flag = 0;
        for (i = 0; i < FRIENDS; i++)
        {
            if (friendRemoved[i])
                continue;
            for (j = 0; j < FRIENDS; j++)
            {
                if (friendRemoved[j])
                    continue;
                akmes[i] += dislike[i][j];
            }
            if (akmes[i] > mostEdges)
            {
                mostEdges = akmes[i];
                mostEdgesPos = i;
                flag = 1;
            }
            else if (akmes[i] == 0)
            {
                zeroEdgesPosT[i] = 1;
            }
        }
        if (flag)
        {
            friendRemoved[mostEdgesPos] = 1;
        }
    }
    while (flag);

    for (i = 0; i < FRIENDS; i++)
    {
        if (zeroEdgesPosT[i])
        {
            maxFriends++;
        }
    }

    int allIDs[FRIENDS];
    secFill(FRIENDS, allIDs, 1, zeroEdgesPos);

    printf("To megisto plithos filwn pou mporoun na prosklithoun einai %d.\n", maxFriends);
    printf("O Stathis exei tis parakatw epiloges:\n");
    loop(FRIENDS, allIDs, maxFriends, FRIENDS, LENGTH, names, FRIENDS, dislike);
    printf("\n");

    system("PAUSE");
    return 0;
}

void fillAray(int SIZE, int tab[], int NUM)
{
    for (int i = 0; i < SIZE; i++)
    {
        tab[i] = NUM;
    }
}

void secFill(int SIZE, int tab[], int start, int excludedPos[])
{
    int counter = start;
    for (int i = 0; i < SIZE; i++)
    {
        while (excludedPos[counter - 1])
        {
            counter++;
        }
        tab[i] = counter;
        counter++;
    }
}

void loop(int SIZE, int tab[], int size, int row, int col, char names[row][col], int disSize, int dislike[disSize][disSize])
{
    int temp[size];
    combinations(tab, temp, 0, SIZE - 1, 0, size, row, col, names, disSize, dislike);
}

void combinations(int tab[], int currCombo[], int start, int end, int index, int size, int row, int col, char names[row][col],
                     int disSize, int dislike[disSize][disSize]){
    if (index == size)
    {
        int allowedComb = 1;
        int j, k;

        for (j = 0; j < size - 1; j++)
        {
            if (allowedComb)
            {
                for (k = j + 1; k < size; k++)
                {
                    if (dislike[currCombo[j] - 1][currCombo[k] - 1])
                    {
                        allowedComb = 0;
                    }
                }
            }
        }

        if (allowedComb)
        {
            printf("-------------\n");
            printf("-------------\n");
            for (j = 0; j < size; j++)
            {
                printf("%s\n", names[currCombo[j] - 1]);
            }
        }
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= size - index; i++)
    {
        currCombo[index] = tab[i];
        combinations(tab, currCombo, i + 1, end, index + 1, size, row, col, names, disSize, dislike);
    }
}
