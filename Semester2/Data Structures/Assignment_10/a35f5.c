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
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTInorder(BinTreePointer Root);
BinTreePointer LCANode(BinTreePointer Root, BinTreePointer node1, BinTreePointer node2);

int main() {
    BinTreePointer ARoot, node1, node2, lca;
    int num1, num2, AnItem;
    boolean found = FALSE;

    CreateBST(&ARoot);

    printf("Enter number of elements for the tree: ");
    scanf("%d", &AnItem);
    for (int i = 0; i < AnItem; i++) {
        printf("Enter number: ");
        scanf("%d", &num1);
        RecBSTInsert(&ARoot, num1);
    }

    printf("Elements of BST in increasing order\n");
    RecBSTInorder(ARoot);
    printf("\n");

    do {
        printf("Give first element of BST:");
        scanf("%d", &num1);
        RecBSTSearch(ARoot, num1, &found, &node1);
        if (!found) {
            printf("To %d den vre8ike sto dentro. Ksanadwse allo ari8mo.\n", num1);
            continue;
        }
        found = FALSE;
        printf("Give second element of BST:");
        scanf("%d", &num2);
        RecBSTSearch(ARoot, num2, &found, &node2);
        if (!found) {
            printf("To %d den vre8ike sto dentro. Ksanadwse allo ari8mo.\n", num2);
        }
    } while (!found);

    lca = LCANode(ARoot, node1, node2);
    printf("LCA node of %d and %d is node with element %d\n", node1->Data, node2->Data, lca->Data);

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

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue < Root->Data)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue > Root->Data)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
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

BinTreePointer LCANode(BinTreePointer Root, BinTreePointer node1, BinTreePointer node2) {
    if (Root == NULL) {
        return NULL;
    }
    if (node1->Data < Root->Data && node2->Data < Root->Data) {
        return LCANode(Root->LChild, node1, node2);
    }
    if (node1->Data > Root->Data && node2->Data > Root->Data) {
        return LCANode(Root->RChild, node1, node2);
    }
    return Root;
}