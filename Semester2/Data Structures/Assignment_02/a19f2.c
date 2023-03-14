#include <stdio.h>
#include <stdlib.h>

#define StackLimit 8

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
void TraverseStack(StackType Stack);
StackElementType minElement(StackType *Stack);
StackElementType maxElement(StackType *Stack);

int main()
{
    StackType S;
    StackElementType item, i;
    CreateStack(&S);

    for (i=0; i<StackLimit; i++)
    {
        printf("Dwse to epomeno stoixeio:");
        scanf("%d",&item);
        Push(&S,item);
    }
    TraverseStack(S);

    printf("Min: %d\n", minElement(&S));
    printf("Max: %d\n", maxElement(&S));

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

StackElementType minElement(StackType*Stack)
{
    StackElementType min, item;
    StackType tempS;

    CreateStack(&tempS);

    Pop(Stack, &min);
    Push(&tempS, min);

    while (!EmptyStack(*Stack))
    {
        Pop(Stack, &item);
        Push(&tempS, item);
        if (min>item)
            min = item;
    }

    while (!EmptyStack(tempS))
    {
        Pop(&tempS, &item);
        if (min!=item)
            Push(Stack, item);
    }

    return min;
}

StackElementType maxElement(StackType *Stack)
{
    StackElementType max, item;
    StackType tempS;

    CreateStack(&tempS);

    Pop(Stack, &max);
    Push(&tempS, max);

    while (!EmptyStack(*Stack))
    {
        Pop(Stack, &item);
        Push(&tempS, item);
        if (max<item)
            max = item;
    }

    while (!EmptyStack(tempS))
    {
        Pop(&tempS, &item);
        if (max!=item)
            Push(Stack, item);
    }

    return max;
}
