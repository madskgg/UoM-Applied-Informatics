#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[21];
    char phone[12];
    int code;
} Teacher;

typedef Teacher BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode
{
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum
{
    FALSE,
    TRUE
} boolean;

void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);

void BuildBST(BinTreePointer *Root);
void RecBSTSearchBySubject(BinTreePointer Root, int code);

int main()
{
    BinTreePointer ARoot,*LocPtr;
    int code;
    BinTreeElementType EmpRec;
    boolean found;

    // 1
    CreateBST(&ARoot);
    BuildBST(&ARoot);

    // 2
    printf("Print teachers data\n");
    RecBSTInorder(ARoot);

    // 3
    for (int i=0; i<=1; i++)
    {
        printf("\nGive teacher full name: ");
        gets(EmpRec.name);
        printf("Give teacher phone number: ");
        gets(EmpRec.phone);
        printf("Give teacher code: ");
        scanf("%d", &EmpRec.code);
        RecBSTInsert(&ARoot, EmpRec);
        getchar();
    }

    // 4
    printf("\nGive teacher full name to search: ");
    gets(EmpRec.name);
    RecBSTSearch(ARoot, EmpRec, &found, LocPtr);
    if (found)
        printf("%s, %s, %d\n", (*LocPtr)->Data.name, (*LocPtr)->Data.phone, (*LocPtr)->Data.code);
    else
        printf("\nTeacher Not Found\n");

    // 5
    printf("\nGive code to search: ");
    scanf("%d", &code);
    RecBSTSearchBySubject(ARoot, code);
    getchar();

    // 6
    printf("\nGive teacher full name to delete: ");
    gets(EmpRec.name);
    RecBSTDelete(&ARoot, EmpRec);

    // 7
    printf("\nPrint teachers data\n");
    RecBSTInorder(ARoot);

    return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root == NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root))
    {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root)->Data = Item;
        (*Root)->LChild = NULL;
        (*Root)->RChild = NULL;
    }
    else if (strcmp(Item.name, (*Root)->Data.name) < 0)
    {
        RecBSTInsert(&((*Root)->LChild), Item);
    }
    else if (strcmp(Item.name, (*Root)->Data.name) > 0)
    {
        RecBSTInsert(&((*Root)->RChild), Item);
    }
    else
    {
        printf("TO STOIXEIO EINAI HDH STO DDA\n");
    }
}


void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
{
    if (BSTEmpty(Root))
        *Found = FALSE;
    else if (strcmp(KeyValue.name, Root->Data.name) < 0)
        RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
    else if (strcmp(KeyValue.name, Root->Data.name) > 0)
        RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
    else
    {
        *Found = TRUE;
        *LocPtr = Root;
    }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
{
    BinTreePointer TempPtr;

    if (BSTEmpty(*Root))
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
    else if (strcmp(KeyValue.name, (*Root)->Data.name) < 0)
        RecBSTDelete(&((*Root)->LChild), KeyValue);
    else if (strcmp(KeyValue.name, (*Root)->Data.name) > 0)
        RecBSTDelete(&((*Root)->RChild), KeyValue);
    else if ((*Root)->LChild ==NULL)
    {
        TempPtr = *Root;
        *Root = (*Root)->RChild;
        free(TempPtr);
    }
    else if ((*Root)->RChild == NULL)
    {
        TempPtr = *Root;
        *Root = (*Root)->LChild;
        free(TempPtr);
    }
    else
    {
        TempPtr = (*Root)->RChild;
        while (TempPtr->LChild != NULL)
            TempPtr = TempPtr->LChild;
        (*Root)->Data = TempPtr->Data;
        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
    }
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root)
    {
        RecBSTInorder(Root->LChild);
        printf("%s, %s, %d\n", Root->Data.name, Root->Data.phone, Root->Data.code);
        RecBSTInorder(Root->RChild);
    }
}

void BuildBST(BinTreePointer *Root)
{
    FILE *fp;
    Teacher EmpRec;
    int nscan;
    char termch;
    fp = fopen("I14F5.TXT", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while (1)
    {
        nscan = fscanf(fp, "%[^,], %[^,],%d%c", EmpRec.name, EmpRec.phone, &EmpRec.code, &termch);
        if (nscan == EOF)
            break;
        if (nscan == 4 && termch == '\n')
            RecBSTInsert(Root, EmpRec);
        else
        {
            printf("Error reading file\n");
            exit(1);
        }
    }
    fclose(fp);
}

void RecBSTSearchBySubject(BinTreePointer Root, int code)
{
    if (Root != NULL)
    {
        RecBSTSearchBySubject(Root->LChild, code);
        if (Root->Data.code == code)
        {
            printf("%s, %s, %d\n", Root->Data.name, Root->Data.phone, Root->Data.code);
        }
        RecBSTSearchBySubject(Root->RChild, code);
    }
}
