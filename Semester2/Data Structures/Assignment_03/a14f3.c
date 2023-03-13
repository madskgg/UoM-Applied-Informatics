#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 100

typedef int QueueElementType;

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
void TraverseQ(QueueType Queue);

void GetNthElementValueA(QueueType *Q, int n, QueueElementType *item);
void GetNthElementValueB(QueueType Q, int n, QueueElementType *item);

int main()
{
    QueueElementType item;
    QueueType AQueue;
    int n;

    CreateQ(&AQueue);

    for (int i=5; i<=100; i+=5)
        AddQ(&AQueue, i);

    TraverseQ(AQueue);

    int num = (AQueue.Rear+QueueLimit-AQueue.Front)%QueueLimit+1;
    do
    {
        printf("Dwse n: ");
        scanf("%d", &n);
    }
    while (n>=num);

    GetNthElementValueA(&AQueue, n, &item);
    printf("ValueA:%d\n", item);
    GetNthElementValueB(AQueue, n, &item);
    printf("ValueB:%d\n", item);

    TraverseQ(AQueue);

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

void TraverseQ(QueueType Queue)
{
    int current;
    if (!EmptyQ(Queue))
    {
        current = Queue.Front;
        while (current != Queue.Rear)
        {
            printf("%d ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
        }
        printf("\n");
    }
    else printf("Empty Queue\n");
}

void GetNthElementValueA(QueueType *Q, int n, QueueElementType *item) {
    QueueType tempQ;
    QueueElementType x;
    int count = 0;

    CreateQ(&tempQ);

    while (!EmptyQ(*Q)) {
        RemoveQ(Q, &x);
        AddQ(&tempQ, x);
        count++;
        if (count == n) {
            *item = x;
        }
    }
    while (!EmptyQ(tempQ)) {
        QueueElementType x;
        RemoveQ(&tempQ, &x);
        AddQ(Q, x);
    }
}

void GetNthElementValueB(QueueType Q, int n, QueueElementType *item) {
    int index = (Q.Front + n - 1) % QueueLimit;
    *item = Q.Element[index];
}
