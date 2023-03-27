#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 10

typedef int QueueElementType;

typedef struct
{
    int Front, Rear, Count;
    QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main()
{
    QueueElementType item;
    QueueType q;
    int num, i;

    CreateQ(&q);

    //A
    printf("(a)\n");
    for (i = 3; i <= 30; i=i+3)
    {
        AddQ(&q, i);
    }
    TraverseQ(q);

    //B
    printf("(b)\n");
    do
    {
        printf("Give a number:");
        scanf("%d", &num);
        if (num % 3 == 0)
            AddQ(&q, num);
        else
            printf("Give a multiple of 3\n");
    }
    while (num % 3 != 0);
    TraverseQ(q);

    //C
    printf("(c)\n");
    RemoveQ(&q, &item);
    TraverseQ(q);
    printf("Removed item=%d\n", item);

    //D
    printf("(d)\n");
    for (i = 0; i < 2; i++)
    {
        do
        {
            printf("Give a number:");
            scanf("%d", &num);
            if (num % 3 == 0)
                AddQ(&q, num);
            else
                printf("Give a multiple of 3\n");
        }
        while (num % 3 != 0);
        TraverseQ(q);
    }

    //E
    printf("(e)\n");
    while (!EmptyQ(q))
    {
        RemoveQ(&q, &item);
        TraverseQ(q);
        printf("Removed item=%d\n", item);
    }

    return 0;
}

void CreateQ(QueueType *Queue)
{
    Queue->Front = 0;
    Queue->Rear = 0;
    Queue->Count = 0;
}

boolean EmptyQ(QueueType Queue)
{
    return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
{
    return (Queue.Count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    if(!EmptyQ(*Queue))
    {
        *Item = Queue ->Element[Queue -> Front];
        Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
        Queue->Count--;
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
        Queue->Count++;
    }
    else
        printf("Full Queue\n");
}

void TraverseQ(QueueType Queue)
{
    int current,i;
    printf("Queue: ");
    if (!EmptyQ(Queue))
    {
        current = Queue.Front;
        for (i=Queue.Count; i>0; i--)
        {
            printf("%d ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
        }
        printf("\n");
    }
    else
        printf("Empty Queue\n");

    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.Count);

}
