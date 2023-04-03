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
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void delete_list_after_n(ListPointer *List, int n);

int main()
{
    ListPointer AList, PredPtr;
    ListElementType Item;
    int n, i, number;

    PredPtr = NULL;

    CreateList(&AList);
    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
        scanf("%d", &Item);
        LinkedInsert(&AList, Item, PredPtr);
    }

    printf("Arxiki lista\n");
    LinkedTraverse(AList);

    printf("\nDWSE TI THESI, META APO TIN OPOIA THA DIAGRAFOYN TA STOIXEIA: ");
    scanf("%d", &n);
    delete_list_after_n(&AList, n);

    printf("Teliki lista\n");
    LinkedTraverse(AList);

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

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
        printf("EMPTY LIST\n");
    else
    {
        if (PredPtr == NULL)
        {
            TempPtr = *List;
            *List = TempPtr->Next;
        }
        else
        {
            TempPtr = PredPtr->Next;
            PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
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

void delete_list_after_n(ListPointer *List, int n)
{
    ListPointer TempPtr, PredPtr;
    int i;

    if (EmptyList(*List))
        printf("EMPTY LIST\n");
    else
    {
        TempPtr = *List;
        i = 0;
        while (TempPtr != NULL && i < n)
        {
            PredPtr = TempPtr;
            TempPtr = TempPtr->Next;
            i++;
        }

        if (i != n)
            printf("Invalid n value\n");

        while (PredPtr->Next != NULL)
            LinkedDelete(List, PredPtr);
    }
}
