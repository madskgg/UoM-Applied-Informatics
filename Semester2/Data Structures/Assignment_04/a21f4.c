#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 20
#define NilValue -1

typedef struct
{
    int studentId;
    float grade;
} ListElementType;

typedef int ListPointer;
typedef struct
{
    ListElementType Data;
    ListPointer Next;
} NodeType;

typedef enum
{
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;

    int n,i;
    CreateList(&AList);
    InitializeStoragePool(Node, &FreePtr);
    printf("DWSE ARI8MO MA8HTWN:");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("DWSE ARI8MO MHTRWOU GIA EISAGWGH STH LISTA: ");
        scanf("%d", &Node[i].Data.studentId);
        printf("DWSE BA8MO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &Node[i].Data.grade);
        printf("DWSE TH 8ESH META THN OPOIA 8A GINEI H EISAGWGH STOIXEIOY: ");
        scanf("%d",&PredPtr);

        Insert(&AList, Node, &FreePtr, PredPtr, Node[i].Data);
        printf("\nPlithos stoixeiwn sth lista %d\n", FreePtr);
        TraverseLinked(AList, Node);
    }

    printf("DWSE TH 8ESH TOY PROHGOUMENOY STOIXEIOY GIA DIAGRAFH: ");
    scanf("%d",&PredPtr);
    Delete(&AList, Node, &FreePtr, PredPtr);
    printf("\nPlithos stoixeiwn sth lista %d\n", FreePtr);
    TraverseLinked(AList, Node);

    for (i=n; i<n+2; i++)
    {
        printf("DWSE ARI8MO MHTRWOU GIA EISAGWGH STH LISTA: ");
        scanf("%d", &Node[i].Data.studentId);
        printf("DWSE BA8MO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &Node[i].Data.grade);
        printf("DWSE TH 8ESH META THN OPOIA 8A GINEI H EISAGWGH STOIXEIOY: ");
        scanf("%d",&PredPtr);

        Insert(&AList, Node, &FreePtr, PredPtr, Node[i].Data);
        printf("\nPlithos stoixeiwn sth lista %d\n", FreePtr);
        TraverseLinked(AList, Node);
    }

    return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
    int i;

    for (i=0; i<NumberOfNodes-1; i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.studentId=-1;
        Node[i].Data.grade=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.studentId=-1;
    Node[NumberOfNodes-1].Data.grade=-1;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
{
    *List=NilValue;
}

boolean EmptyList(ListPointer List)
{
    return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
{
    return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
    *P = *FreePtr;
    if (!FullList(*FreePtr))
        *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
{
    Node[P].Next =*FreePtr;
    Node[P].Data.studentId=-1;
    Node[P].Data.grade=-1;

    *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
    ListPointer TempPtr;
    GetNode(&TempPtr,FreePtr,Node);
    if (!FullList(TempPtr))
    {
        if (PredPtr==NilValue)
        {
            Node[TempPtr].Data = Item;
            Node[TempPtr].Next =*List;
            *List =TempPtr;
        }
        else
        {
            Node[TempPtr].Data =Item;
            Node[TempPtr].Next =Node[PredPtr].Next;
            Node[PredPtr].Next =TempPtr;
        }
    }
    else
        printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
{
    ListPointer TempPtr ;

    if (!EmptyList(*List))
    {
        if (PredPtr == NilValue)
        {
            TempPtr =*List;
            *List =Node[TempPtr].Next;
        }
        else
        {
            TempPtr =Node[PredPtr].Next;
            Node[PredPtr].Next =Node[TempPtr].Next;
        }
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
        printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
    ListPointer CurrPtr;

    if (!EmptyList(List))
    {
        CurrPtr =List;
        while (CurrPtr != NilValue)
        {
            printf("[%d: (%d,%g) ->%d] ", CurrPtr,Node[CurrPtr].Data.studentId, Node[CurrPtr].Data.grade,Node[CurrPtr].Next);
            CurrPtr=Node[CurrPtr].Next;
        }
        printf("\n");
    }
    else printf("Empty List ...\n");
}
