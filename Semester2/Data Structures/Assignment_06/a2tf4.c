#include <stdio.h>
#include <stdlib.h>

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
    ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum
{
    FALSE, TRUE
} boolean;

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void difference_list(ListPointer AList, ListPointer BList, ListPointer *FinalList);

int main()
{
    ListPointer AList, BList, FinalList, PredPtr;
    ListElementType Item;
    int n, i;

    PredPtr = NULL;

    CreateList(&AList);
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d", &Item);
        LinkedInsert(&AList, Item, PredPtr);
    }

    CreateList(&BList);
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
        scanf("%d", &Item);
        LinkedInsert(&BList, Item, PredPtr);
    }

    printf("1h lista\n");
    LinkedTraverse(AList);
    printf("\n2h lista\n");
    LinkedTraverse(BList);

    CreateList(&FinalList);
    difference_list(AList, BList, &FinalList);
    printf("\nTeliki lista\n");
    LinkedTraverse(FinalList);

    return 0;
}

void CreateList(ListPointer *List)
{
    *List = NULL;
}

boolean EmptyList(ListPointer List)
{
    return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
    ListPointer TempPtr;

    TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
    TempPtr->Data = Item;
    if (PredPtr==NULL)
    {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else
    {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}


void LinkedTraverse(ListPointer List)
{
    ListPointer CurrPtr;

    if (EmptyList(List))
        printf("EMPTY LIST\n");
    else
    {
        CurrPtr = List;
        while ( CurrPtr!=NULL )
        {
            printf("%d ", CurrPtr->Data);
            CurrPtr = CurrPtr->Next;
        }
    }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
    ListPointer CurrPtr;
    boolean stop;

    CurrPtr = List;
    *PredPtr=NULL;
    stop= FALSE;
    while (!stop && CurrPtr!=NULL )
    {
        if (CurrPtr->Data==Item )
            stop = TRUE;
        else
        {
            *PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
        }
    }
    *Found=stop;
}

void difference_list(ListPointer AList, ListPointer BList, ListPointer *FinalList)
{
    ListPointer CurrPtr, PredPtr, CurrPtr2, Temp;
    ListElementType Item;
    boolean found, done;

    CurrPtr = AList;
    PredPtr = NULL;
    Temp = PredPtr;

    while (CurrPtr != NULL)
    {
        CurrPtr2 = BList;
        done = FALSE;
        while (CurrPtr2 != NULL && !done)
        {
            if (CurrPtr->Data == CurrPtr2->Data)
                done = TRUE;
            else
                CurrPtr2 = CurrPtr2->Next;
        }

        Item = CurrPtr->Data;
        if (!done)
        {
            found = FALSE;
            LinearSearch(*FinalList, Item, &Temp, &found);
            if (!found)
                LinkedInsert(FinalList, Item, PredPtr);
        }
        Temp = PredPtr;
        CurrPtr = CurrPtr->Next;
    }
}


