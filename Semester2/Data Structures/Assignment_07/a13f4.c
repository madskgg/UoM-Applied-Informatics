#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QueueLimit 50

typedef struct
{
    char name[9];
    char filename[13];
} QueueElementType;

typedef struct
{
    int Front, Rear;
    QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);


int main()
{
    QueueType AQueue, BQueue;
    QueueElementType AnItem;
    FILE *fp;

    CreateQ(&AQueue);
    CreateQ(&BQueue);

    fp = fopen("i13f4.dat", "r");
    if (fp == NULL)
    {
        printf("Error: File not found");
        return 1;
    }

    while (fscanf(fp, "%s %s", AnItem.name, AnItem.filename) != EOF)
    {
        if (strstr(AnItem.name, "USER") != NULL || strstr(AnItem.name, "FORT") != NULL)
            AddQ(&AQueue, AnItem);
        else
            AddQ(&BQueue, AnItem);
    }

    while (!EmptyQ(BQueue)) {
        RemoveQ(&BQueue, &AnItem);
        printf("Printing the job of %s, %s\n", AnItem.name, AnItem.filename);
        printf("Press any key to continue");
        getchar();
    }

    while (!EmptyQ(AQueue)) {
        RemoveQ(&AQueue, &AnItem);
        printf("Printing the job of %s, %s\n", AnItem.name, AnItem.filename);
        printf("Press any key to continue");
        getchar();
    }

    printf("There are no jobs in the printing queue");

    fclose(fp);

    return 0;
}

void CreateQ(QueueType *Queue)
{
    Queue->Front = 0;
    Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
{
    return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
{
    return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    if(!EmptyQ(*Queue))
    {
        *Item = Queue ->Element[Queue -> Front];
        Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
    }
    else
        printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
    if(!FullQ(*Queue))
    {
        Queue ->Element[Queue ->Rear] = Item;
        Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
    }
    else
        printf("Full Queue\n");
}





