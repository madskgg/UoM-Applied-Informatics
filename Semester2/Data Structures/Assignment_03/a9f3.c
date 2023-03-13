#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QueueLimit1 3
#define QueueLimit2 20

typedef char QueueElementType1[25];

typedef struct
{
    int Front, Rear;
    QueueElementType1 Element[QueueLimit1];
} QueueType1;

typedef struct
{
    QueueElementType1 name;
    int code;
    char phoneNumber[10];
} QueueElementType2;

typedef struct
{
    int Front, Rear;
    QueueElementType2 Element[QueueLimit2];
} QueueType2;

typedef enum { FALSE, TRUE } boolean;

void CreateQ(QueueType1 *Queue);
boolean EmptyQ(QueueType1 Queue);
boolean FullQ(QueueType1 Queue);
void RemoveQ(QueueType1 *Queue, QueueElementType1 *Item);
void AddQ(QueueType1 *Queue, QueueElementType1 Item);

void CreateWQ(QueueType2 *waitingQ);
boolean EmptyWQ(QueueType2 waitingQ);
boolean FullWQ(QueueType2 waitingQ);
void RemoveWQ(QueueType2 *waitingQ, QueueElementType2 *Item);
void AddWQ(QueueType2 *waitingQ, QueueElementType2 Item);

void newAppointment(int code, QueueType1 *Q, QueueType2 *waitingQ);
void showWaitingQ(QueueType2 waitingQ);
void showQ(int i,QueueType1 *Queue);

int main()
{
    QueueType1 Q[6];
    QueueType2 waitingQ;
    int code;

    for (int i = 1; i <= 5; i++)
    {
        CreateQ(&Q[i]);
    }

    CreateWQ(&waitingQ);

    srand(54);

    char choice='Y';

    do
    {
        code = rand() % 5 + 1;
        newAppointment(code, Q, &waitingQ);

        printf("Continue Y/N (Y=yes, N=No): ");
        scanf("%c", &choice);
        getchar();
    }
    while (choice != 'N' && choice != 'n');

    for (int i = 1; i <= 5; i++)
    {
        showQ(i, &Q[i]);
    }

    printf("\nWaiting list:\n");
    showWaitingQ(waitingQ);

    return 0;
}

// Queue
void CreateQ(QueueType1 *Queue)
{
    Queue->Front = 0;
    Queue->Rear = 0;
}

boolean EmptyQ(QueueType1 Queue)
{
    return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType1 Queue)
{
    return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit1));
}

void AddQ(QueueType1 *Queue, QueueElementType1 Item)
{
    if (!FullQ(*Queue))
    {
        strcpy(Queue->Element[Queue->Rear], Item);
        Queue->Rear = (Queue->Rear + 1) % QueueLimit1;
    }
    else
    {
        printf("Full Queue\n");
    }
}

// Waiting Queue
void CreateWQ(QueueType2 *waitingQ)
{
    waitingQ->Front = 0;
    waitingQ->Rear = 0;
}

boolean EmptyWQ(QueueType2 waitingQ)
{
    return (waitingQ.Front == waitingQ.Rear);
}

boolean FullWQ(QueueType2 waitingQ)
{
    return ((waitingQ.Front) == ((waitingQ.Rear +1) % QueueLimit2));
}

void AddWQ(QueueType2 *waitingQ, QueueElementType2 Item)
{
    if(!FullWQ(*waitingQ))
    {
        strcpy(waitingQ->Element[waitingQ->Rear].name, Item.name);
        strcpy(waitingQ->Element[waitingQ->Rear].phoneNumber, Item.phoneNumber);
        waitingQ->Element[waitingQ->Rear].code = Item.code;
        waitingQ->Rear = (waitingQ->Rear + 1) % QueueLimit2;
    }
    else
        printf("Full Queue\n");
}

//

void newAppointment(int code, QueueType1 *Q, QueueType2 *waitingQ)
{
    boolean flag = FALSE;
    QueueElementType1 name, phoneNumber;
    QueueElementType2 patient;
    printf("Give your name: ");
    gets(name);
    if (!FullQ(Q[code]))
    {
        AddQ(&Q[code], name);
        printf("Successful appointment for clinic %d\n", code);
    }
    else
    {
        flag = TRUE;
    }
    if (flag)
    {
        printf("You are in a waiting list\n");
        printf("Give your phone number: ");
        gets(phoneNumber);
        strcpy(patient.name, name);
        patient.code = code;
        strcpy(patient.phoneNumber, phoneNumber);
        AddWQ(waitingQ, patient);
    }
}

void showWaitingQ(QueueType2 waitingQ)
{
    QueueElementType2 patient;
    int current;
    current  = waitingQ.Front;
    if (!EmptyWQ(waitingQ))
    {
        while (current != waitingQ.Rear)
        {
            patient = waitingQ.Element[current];
            printf("%s, %d, %s\n", patient.name, patient.code, patient.phoneNumber);
            current = (current + 1) % QueueLimit2;
        }
    }
}

void showQ(int i, QueueType1 *Queue)
{
    printf("\nAppointments of clinic %d\n", i);
    int current;
    if (!EmptyQ(*Queue))
    {
        current = Queue->Front;
        while (current != Queue->Rear)
        {
            printf("%s\n", Queue->Element[current] );
            current = (current + 1) % QueueLimit1;
        }
    }
}

