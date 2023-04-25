#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define StackLimit 50

typedef char StackElementType;

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

int main()
{
    StackType AStack;
    StackElementType AnItem;
    int i;
    char str[40];
    boolean found = TRUE;

    CreateStack(&AStack);

    printf("EISAGETE MIA PARASTASI: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            Push(&AStack, str[i]);
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            if (EmptyStack(AStack))
            {
                found = FALSE;
                break;
            }
            else
            {
                Pop(&AStack, &AnItem);
                if ((AnItem == '(' && str[i] != ')') || (AnItem == '{' && str[i] != '}') || (AnItem == '[' && str[i] != ']'))
                {
                    found = FALSE;
                    break;
                }
            }
        }
    }

    if (found == FALSE || !EmptyStack(AStack))
        printf("WRONG\n");
    else
        printf("CORRECT\n");

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
