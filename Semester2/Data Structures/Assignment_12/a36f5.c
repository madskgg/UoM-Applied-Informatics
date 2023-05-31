#include <stdio.h>
#include <stdlib.h>

#define  MaxElements 8       

typedef char HeapElementType;    
typedef  struct { 
     HeapElementType key;
    // int Data;                
} HeapNode;

typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMaxHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMaxHeap(HeapType *Heap, HeapNode Item);
boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right);
void PrintHeap(HeapType Heap);

int main() {
    HeapType AHeap;
    HeapNode AnItem;
    HeapElementType ArgKey;
    int i, left, right;

    CreateMaxHeap(&AHeap);

    for (i = 1; i <= 8; i++) {
        printf("Enter a letter : ");
        scanf(" %c", &ArgKey);
        AnItem.key = ArgKey;
        InsertMaxHeap(&AHeap, AnItem);
    }

    PrintHeap(AHeap);

    for (i = 1; i <= 4; i++) {
        printf("Enter a letter : ");
        scanf(" %c", &ArgKey);

        if (Search(AHeap, ArgKey, &left, &right)) {
            printf("L=%d, R=%d\n", left, right);

            if (left != -1)
                printf("%c %c\n", AHeap.Element[left].key, AHeap.Element[right].key);
            else
                printf("\n");
        } 
        else 
            printf("Not found\n");
    }

    return 0;
}

void CreateMaxHeap(HeapType *Heap)
{
  (*Heap).Size=0;
}

boolean FullHeap(HeapType Heap)
{
  return (Heap.Size==MaxElements);
}

void InsertMaxHeap(HeapType *Heap, HeapNode Item)
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>1 && Item.key > Heap->Element[hole/2].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole/2];
                      hole=hole/2;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

boolean Search(HeapType Heap, HeapElementType ArgKey, int *left, int *right) {
    boolean found = FALSE;
    int i = 1;

    while (!found && i <= Heap.Size) {
        if (ArgKey != Heap.Element[i].key) {
            i++;
        } else {
            *left = *right = -1;

            if (2 * i <= Heap.Size) {
                *left = 2 * i;
                if (2*i+1 <= Heap.Size)
                *right = 2 * i + 1;
            }

            found = TRUE;
        }
    }

    return found;
}

void PrintHeap(HeapType Heap)
{
    int i,l,r,n;
    printf("Size=%d\n",Heap.Size);
     printf("N L R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%c, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%c, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%c \n",Heap.Element[r].key);
         else printf("\n");
     }
     printf("Heap array\n");
     for (i=1; i<=Heap.Size;i++)
        printf("%c ",Heap.Element[i].key);
    printf(" \n");
}