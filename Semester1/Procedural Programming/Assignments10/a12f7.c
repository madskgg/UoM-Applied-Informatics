#include <stdio.h>
#include <string.h>
#include "simpio.h"

#define PASSENGERS 100
#define LENGTH 20

int main()
{
    char theseis[PASSENGERS][LENGTH];
    int num_passengers = 0;

    char name[LENGTH];

    int i=0;
    while (i<PASSENGERS)
    {
        printf("Passenger in seat %d :", i+1);
        gets(name);
        if (strcmp(name, "----") == 0)
        {
            break;
        }

        int name_exists = 0;
        for (int i = 0; i < num_passengers; i++)
        {
            if (strcmp(name, theseis[i]) == 0)
            {
                name_exists = 1;
                break;
            }
        }

        if (name_exists)
        {
            printf("Passenger %s already exists.\n", name);
        }
        else if (num_passengers >= PASSENGERS)
        {
            printf("The aircraft is full.\n");
            break;
        }
        else
        {
            strcpy(theseis[num_passengers], name);
            num_passengers++;
            i++;
        }
    }

    printf("\nPassenger List\n");
    printf("--------------\n");
    for (int i = 0; i < num_passengers; i++)
    {
        printf("In seat %d :%s\n", i+1, theseis[i]);
    }

    return 0;
}
