#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int Sum_Cube(int i);
bool IsArmstrong(int i);
int cube(int x);

int main()
{
    int i;

    for (i=1; i<1000; i++)
    {
        if (IsArmstrong(i))
            printf("%d\n", i);
    }
    return 0;
}

int cube(int x)
{
    int i;
    int p=1;
    for (i=0; i<3; i++)
        p*=x;
    return p;

}

int Sum_Cube(int i)
{
    int d1,d2,d3;

    d1=i%10;
    d2=(i/10)%10;
    d3=(i/100);

    return cube(d1)+cube(d2)+cube(d3);
}

bool IsArmstrong(int i)
{
    return (Sum_Cube(i)==i);
}
