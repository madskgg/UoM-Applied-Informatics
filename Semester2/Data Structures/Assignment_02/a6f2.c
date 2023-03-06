#include <stdio.h>
#include <stdlib.h>

#define StackLimit 60

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

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void GetTopElementA(StackType *Stack, StackElementType *topElement);
void GetTopElementB(StackType Stack, StackElementType *topElement);
void TraverseStack(StackType Stack);

int main()
{
    StackType S;
    StackElementType topElement, i;
    CreateStack(&S);

    for (i = 2; i <= StackLimit; i += 2)
        Push(&S, i);
    TraverseStack(S);

    GetTopElementA(&S, &topElement);
    printf("Top with GetTopElementA = %d\n", topElement);
    TraverseStack(S);

    GetTopElementB(S, &topElement);
    printf("Top with GetTopElementB = %d\n", topElement);
    TraverseStack(S);

    return 0;
}

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

void GetTopElementA(StackType *Stack, StackElementType *topElement)
{
    Pop(Stack, topElement);
    Push(Stack, *topElement);
}

void GetTopElementB(StackType Stack, StackElementType *topElement)
{
    *topElement = Stack.Element[Stack.Top];
}

void TraverseStack(StackType Stack)
{
    StackElementType i;

    if (EmptyStack(Stack))
        printf("Empty Stack\n");
    else
    {
        printf("plithos sto stack %d\n",Stack.Top+1);
        for (i=0; i<=Stack.Top; i++)
        {
            printf("%d ",Stack.Element[i]);
        }
        printf("\n");
    }
}
