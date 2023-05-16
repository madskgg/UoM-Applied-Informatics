#include <stdio.h>
#include <stdlib.h>

typedef int BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTInorder(BinTreePointer Root);

int RightNodeCount(BinTreePointer Root);

int main() {
    BinTreePointer ARoot;
    int num, x;

    CreateBST(&ARoot);

    printf("Enter number of elements for the tree: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        printf("Enter number: ");
        scanf("%d", &x);
        RecBSTInsert(&ARoot, x);
    }

    printf("Elements of BST in increasing order\n");
    RecBSTInorder(ARoot);
    printf("\n");
    int count = RightNodeCount(ARoot);
    printf("RightNodeCount = %d\n", count);

    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild);
        printf("%d ",Root->Data);
    //    printf("R");
        RecBSTInorder(Root->RChild);
    }
   // printf("U");
}

int RightNodeCount(BinTreePointer Root){
    int lcount = 0, rcount = 0;

    if (Root == NULL)
        return 0;
     if (Root->LChild)
        lcount = RightNodeCount(Root->LChild);

    if (Root->RChild)
        rcount = RightNodeCount(Root->RChild) + 1;

    return lcount + rcount;
}
