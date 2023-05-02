#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define StackLimit 10

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

typedef BinTreePointer StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void NonRecTraversal (BinTreePointer Root);

int main() {
    BinTreePointer Root1, Root2;
    char *word = "ALGORITHM";
    int i;
    CreateBST(&Root1);
    CreateBST(&Root2);
    for (i = 0; i < strlen(word); i++) {
        BSTInsert(&Root1, word[i]);
    }
    for (i = strlen(word) - 1; i >= 0; i--) {
        BSTInsert(&Root2, word[i]);
    }
    printf("First tree\n");
    NonRecTraversal(Root1);
    printf("\nSecond tree\n");
    NonRecTraversal(Root2);
    return 0;
}

void NonRecTraversal(BinTreePointer Root) {
    StackType TempStack;
    BinTreePointer AnItem;
    CreateStack(&TempStack);
    Push(&TempStack, Root);

    while (!EmptyStack(TempStack)) {
        Pop(&TempStack, &AnItem);
        printf("%c ", AnItem->Data);

        if (AnItem->RChild != NULL) {
            Push(&TempStack, AnItem->RChild);
        }

        if (AnItem->LChild != NULL) {
            Push(&TempStack, AnItem->LChild);
        }
    }
}

// TREES

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
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
    else {
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

// STACKS

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
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}
