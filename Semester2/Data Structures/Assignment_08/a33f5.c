#include <stdio.h>
#include <stdlib.h>

typedef int BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum
{
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
BinTreeElementType MinBSTValue(BinTreePointer Root);
BinTreeElementType MaxBSTValue(BinTreePointer Root);

int main()
{
    BinTreePointer ARoot, BRoot;
    CreateBST(&ARoot);
    CreateBST(&BRoot);
    BinTreeElementType AnItem;
    do
    {
        printf("Dose enan thetiko akeraio:");
        scanf("%d", &AnItem);
        if (AnItem != -1)
        {
            if (AnItem % 2 == 0)
            {
                BSTInsert(&BRoot, AnItem);
            }
            else
            {
                BSTInsert(&ARoot, AnItem);
            }
        }
    }
    while (AnItem != -1);

    printf("H mikroteri timi toy DDA twn perittvn arithmwn einai: %d\n", MinBSTValue(ARoot));
    printf("H megalyteri timi toy DDA twn perittvn arithmwn einai: %d\n", MaxBSTValue(ARoot));
    printf("H mikroteri timi toy DDA twn artiwn arithmwn einai: %d\n", MinBSTValue(BRoot));
    printf("H megalyteri timi toy DDA twn artiwn arithmwn einai: %d\n", MaxBSTValue(BRoot));

    return 0;
}

BinTreeElementType MinBSTValue(BinTreePointer Root)
{
    BinTreePointer current = Root;

    while (current->LChild != NULL)
    {
        current = current->LChild;
    }
    return current->Data;
}

BinTreeElementType MaxBSTValue(BinTreePointer Root)
{
    BinTreePointer current = Root;

    while (current->RChild != NULL)
    {
        current = current->RChild;
    }
    return current->Data;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL)
    {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    else
    {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}
