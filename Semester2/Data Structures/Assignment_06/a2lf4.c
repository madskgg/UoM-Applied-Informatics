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
void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void MergeLinkedLists(ListPointer *List, ListPointer BList);

int main()
{
    ListPointer List, BList, PredPtr;
    ListElementType Item;
    boolean Found;
    int n, i;

    CreateList(&List);
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d", &Item);
        OrderedLinearSearch(List, Item, &PredPtr, &Found);
        LinkedInsert(&List, Item, PredPtr);
    }

    CreateList(&BList);
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
        scanf("%d", &Item);
        OrderedLinearSearch(BList, Item, &PredPtr, &Found);
        LinkedInsert(&BList, Item, PredPtr);
    }

    printf("1i lista\n");
    LinkedTraverse(List);
    printf("\n2i lista\n");
    LinkedTraverse(BList);

    MergeLinkedLists(&List, BList);
    printf("\nTeliki lista\n");
    LinkedTraverse(List);

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
             printf("%d, ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
    }
}

void OrderedLinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
    ListPointer CurrPtr;
    boolean DoneSearching;

    CurrPtr = List;
    *PredPtr = NULL;
    DoneSearching = FALSE;
    *Found = FALSE;
    while (!DoneSearching && CurrPtr!=NULL )
    {
        if (CurrPtr->Data>=Item )
        {
            DoneSearching = TRUE;
            *Found = (CurrPtr->Data==Item);
        }
        else
        {
            *PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
        }
    }
}

void MergeLinkedLists(ListPointer *List, ListPointer BList)
{
    ListPointer CurrPtr, TempPtr, PredPtr;
    ListElementType Item;
    boolean Found;

    if (EmptyList(BList))
        printf("EMPTY LIST\n");
    else
    {
        CurrPtr = BList;
        while (CurrPtr != NULL)
        {
            Item = CurrPtr->Data;
            OrderedLinearSearch(*List, Item, &PredPtr, &Found);
            LinkedInsert(List, Item, PredPtr);
            CurrPtr = CurrPtr->Next;
        }
    }
}
