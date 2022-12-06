#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main()
{
    int N, i, code, sex, weight, height, age, max_code, max_sex, max_weight, max_height, max_age;

    printf("Dwse to plhthos: ");
    N = GetInteger();

    max_height = 0;

    for (i=0; i<N; i++)
    {
        printf("Dwse ton kwdiko: ");
        code = GetInteger();
        printf("Dwse to fyllo: ");
        sex = GetInteger();
        printf("Dwse to baros: ");
        weight = GetInteger();
        printf("Dwse to ypsos: ");
        height = GetInteger();
        printf("Dwse thn hlikia: ");
        age = GetInteger();

        if ((sex==0)&&(height>max_height))
        {
            max_code = code;
            max_sex = 0;
            max_weight = weight;
            max_height = height;
            max_age = age;
        }
    }

    printf("%d %d %d %d %d", max_code, max_sex, max_weight, max_height, max_age);

    return 0;
}
