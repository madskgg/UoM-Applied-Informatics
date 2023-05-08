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

int BSTDepth(BinTreePointer Root);

int main()
{
    BinTreePointer Root;
    CreateBST(&Root);
    BSTInsert(&Root, 'P');
    BSTInsert(&Root, 'R');
    BSTInsert(&Root, 'O');
    BSTInsert(&Root, 'C');
    BSTInsert(&Root, 'E');
    BSTInsert(&Root, 'D');
    BSTInsert(&Root, 'U');
    BSTInsert(&Root, 'R');
    BSTInsert(&Root, 'E');
    printf("To vathos toy DDA einai: %d", BSTDepth(Root));
    return 0;
}

int BSTDepth(BinTreePointer Root)
{
    if (Root == NULL)
        return 0;
    else
    {
        int leftDepth = BSTDepth(Root->LChild);
        int rightDepth = BSTDepth(Root->RChild);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
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
