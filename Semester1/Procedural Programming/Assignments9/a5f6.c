#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define S 100

void inputArray(int N, int tab[]);
void inputNumbers(int *a, int *b);
void performCalculations(int a, int b, int N, int tab[], int *count1, int *count2, int *count3);
void ShowResults(int N, int tab[], int a, int b, int count1, int count2, int count3);

int main()
{
    int i, tab[S], N, a, b, count1, count2, count3;
    printf("Give n: ");
    N = GetInteger();
    inputArray(N, tab);

    inputNumbers(&a, &b);

    performCalculations(a, b, N, tab, &count1, &count2, &count3);

    ShowResults(N, tab, a, b, count1, count2, count3);

    return 0;
}

void inputArray(int N, int tab[])
{
    int i;

    for (i=0; i<N; i++)
    {
        printf("Give element [%d]: ", i);
        tab[i]= GetInteger();
    }
}

void inputNumbers(int *a, int *b)
{
    do
    {
    printf("Give A: ");
    *a = GetInteger();
    printf("Give B: ");
    *b = GetInteger();
    if (*a>*b)
        printf("WARNING: A must be smaller than B\n");
    } while (*a>*b);

    printf("\n");
}

void performCalculations(int a, int b, int N, int tab[], int *count1, int *count2, int *count3)
{
  int i;

  *count1=0;
  *count2=0;
  *count3=0;

  for (i=0; i<N; i++)
  {
      if (tab[i]<=a) {(*count1)++;}
      if (tab[i]>=b) {(*count2)++;}
      if (tab[i]>a && tab[i]<b) {(*count3)++;}
  }
}

void ShowResults(int N, int tab[], int a, int b, int count1, int count2, int count3)
{
    int i;
    printf("----The numbers of the array----\n");
    for (i=0; i<N; i++)
        printf("%d ", tab[i]);

    printf("\nA = %d\n", a);
    printf("B = %d\n", b);
    printf("Numbers smaller or equal to A: %d\n", count1);
    printf("Numbers bigger or equal to A: %d\n", count2);
    printf("Numbers bigger than A and smaller than B: %d", count3);

}
