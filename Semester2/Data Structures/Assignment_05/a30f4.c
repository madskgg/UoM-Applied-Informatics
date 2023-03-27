#include <stdio.h>
#include <stdlib.h>

#define NumberOfNodes 10
#define NilValue -1
#define StackLimit 20

typedef struct
{
    int id;
    float grade;
} ListElementType;

typedef int ListPointer;

typedef struct
{
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef int StackElementType;

typedef struct
{
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum
{
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main()
{
    NodeType Node[NumberOfNodes];
    ListPointer AList, FreePtr, PredPtr;
    ListElementType AnItem;
    StackElementType AM;
    StackType Stack;
    int i;
    float min;

    //A
    InitializeStoragePool(Node, &FreePtr);

    //B
    CreateList(&AList);

    //C
    printf("Question C\n");
    printAll(AList, FreePtr, Node);

    //D
    printf("Question D\n");
    TraverseLinked(AList, Node);

    //E
    printf("Question E\n");
    PredPtr=NilValue;

    for(i=0; i<5; i++)
    {
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf("%d", &AnItem.id);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &AnItem.grade);
        Insert(&AList, Node,&FreePtr, PredPtr, AnItem);
    }

    //F
    printf("Question F\n");
    printAll(AList, FreePtr, Node);

    //G
    printf("Question G\n");
    TraverseLinked(AList, Node);

    //H
    printf("Question H\n");
    if (EmptyList(AList))
        printf("Empty List\n");
    else printf("Not an Empty List\n");

    //I
    printf("Question I\n");
    if (FullList(FreePtr))
        printf("Full List\n");
    else printf("Not a Full List\n");

    //J
    printf("Question J\n");
    min=FindMins(AList, Node, &Stack);
    printf("Min value=%.1f\n",min);
    printf("AM with min grade are: ");
    while(!EmptyStack(Stack))
    {
        Pop(&Stack, &AM);
        printf("%d ",AM);
    }

    //K
    printf("\nQuestion K");
    TraverseStack(Stack);

    //L
    printf("Question L\n");
    printAll(AList, FreePtr, Node);

    //M
    printf("Question M\n");
    TraverseLinked(AList, Node);

    return 0;
}

//Functions

//Lists
void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
    int i;

    for (i=0; i<NumberOfNodes-1; i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.id=-1;
        Node[i].Data.grade=-1.0;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.id=-1;
    Node[NumberOfNodes-1].Data.grade=-1.0;
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

void TraverseLinked(ListPointer List, NodeType Node[])
{
    ListPointer CurrPtr;

    printf("Linked list\n");
    if (!EmptyList(List))
    {
        CurrPtr =List;
        while (CurrPtr != NilValue)
        {
             printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.id, Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
            CurrPtr=Node[CurrPtr].Next;
        }
        printf("\n");
    }
    else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("Storage pool\n");
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ",i,Node[i].Data.id, Node[i].Data.grade, Node[i].Next);
    printf("\n");
}

//Stack

void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack))
    {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    }
    else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack))
    {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    }
    else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

//

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack)
{
    ListPointer CurrPtr;
    float min;
    StackElementType Item, studentId;

    CreateStack(Stack);

    if(!EmptyList(List))
    {
        CurrPtr=List;
        min=Node[CurrPtr].Data.grade;

        while(CurrPtr!=NilValue)
        {
            if(Node[CurrPtr].Data.grade<=min)
            {
                if(Node[CurrPtr].Data.grade<min)
                {
                    while(!EmptyStack(*Stack))
                    {
                        Pop(&(*Stack), &Item);
                    }
                    min=Node[CurrPtr].Data.grade;
                }

                studentId = Node[CurrPtr].Data.id;
                Push(&(*Stack), studentId);
            }
            CurrPtr = Node[CurrPtr].Next;
        }
    }
    else
    {
        printf("Empty List...");
    }

    return min;
}
