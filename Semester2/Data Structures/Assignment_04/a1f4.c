#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10
#define NilValue -1

typedef int ListElementType;
typedef int ListPointer;

typedef struct
{
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum
{
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
boolean FullList(ListPointer List);
boolean EmptyList(ListPointer List);
void TraverseLinked(ListPointer List, NodeType Node[]);
boolean Search(ListPointer FreePtr, ListPointer List, NodeType Nodes[NumberOfNodes], ListElementType Item, ListPointer *PredPtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

int main()
{
    ListPointer AList;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    boolean found;
    int i;

    ListElementType AnItem;

    char ch;

    InitializeStoragePool(Node, &FreePtr);

    CreateList(&AList);

    printf("Question C\n");
    printf("Storage pool\n");
    printAll(AList, FreePtr, Node);

    printf("Question D\n");
    printf("Linked list\n");
    TraverseLinked(AList, Node);

    printf("Question E\n");
    do
    {
        printf("Give a number: ");
        scanf("%d", &AnItem);

        found=Search(FreePtr, AList, Node, AnItem, &PredPtr);

        Insert(&AList, Node, &FreePtr, PredPtr, AnItem);

        printf("\nContinue Y/N: ");

        do
        {
            scanf("%c", &ch);
        }
        while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');

    }
    while (toupper(ch)!='N');

    printf("Question F\n");
    printf("Storage pool\n");
    printAll(AList, FreePtr, Node);

    printf("Question G\n");
    printf("Linked list\n");
    TraverseLinked(AList, Node);

    printf("Question H\n");
    if(EmptyList(AList))
        printf("Empty List\n");
    else
        printf("Not an Empty List\n");

    printf("Question I\n");
    if(FullList(FreePtr))
        printf("Full List\n");
    else
        printf("Not a Full List\n");

    printf("Question J\n");
    printf("Search for a number\n");
    for(i=0; i<2; i++)
    {
        printf("Give a number ");
        scanf("%d", &AnItem);

        found=Search(FreePtr, AList, Node, AnItem, &PredPtr);
        if(found)
            printf("The number is in the list and its predecessor is in position %d\n",PredPtr);
        else
            printf("The number is not in the list\n");
    }

    return 0;
}

boolean Search(ListPointer FreePtr, ListPointer List, NodeType Nodes[NumberOfNodes], ListElementType Item, ListPointer *PredPtr)
{
    boolean stop;
    boolean found;
    ListPointer current;

    stop=FALSE;
    found=FALSE;
    *PredPtr = NilValue;

    if(!EmptyList(List))
    {
        current=List;
        while (current != NilValue && !stop)
        {
            if(Nodes[current].Data >= Item)
            {
                stop=TRUE;
                found=(Nodes[current].Data==Item);
            }
            else
            {
                *PredPtr=current;
                current=Nodes[current].Next;
            }
        }
    }

    else
    {
        found=FALSE;
    }

    return found;
}

void CreateList(ListPointer *List)
{
    *List=NilValue;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
    int i;

    for (i=0; i<NumberOfNodes; i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
    *FreePtr=0;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
    ListPointer TempPtr;
    GetNode(&TempPtr,FreePtr,Node);
    if (!FullList(TempPtr))
    {
        if (PredPtr==NilValue)
        {
            Node[TempPtr].Data =Item;
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

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
    *P = *FreePtr;
    if (!FullList(*FreePtr))
        *FreePtr =Node[*FreePtr].Next;
}

boolean EmptyList(ListPointer List)
{
    return (List==NilValue);
}

boolean FullList(ListPointer List)
{
    return (List==NilValue);
}

void TraverseLinked(ListPointer List, NodeType Node[])
{
    ListPointer CurrPtr;

    if (!EmptyList(List))
    {
        CurrPtr =List;
        while (CurrPtr != NilValue)
        {
            printf("(%d: %d ->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
            CurrPtr=Node[CurrPtr].Next;
        }
        printf("\n");
    }
    else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0; i<NumberOfNodes; i++)
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}
