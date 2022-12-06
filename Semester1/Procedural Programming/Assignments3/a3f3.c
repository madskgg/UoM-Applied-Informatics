#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main()
{
    long interiorboxes, foreignboxes, intdaily, fordaily, inttotal, fortotal, total;

    inttotal = fortotal = intdaily = fordaily = 0;

    do
    {
      printf("Kibwtia eswterikou? ");
      interiorboxes = GetLong();
      if (interiorboxes!=-9999)
      {
          printf("Kibwtia exwterikou? ");
          foreignboxes = GetLong();

          intdaily = interiorboxes*10;
          fordaily = foreignboxes*15;
          total = intdaily + fordaily;
          inttotal += intdaily;
          fortotal += fordaily;

          printf("%10ld %10ld %10ld\n", intdaily, fordaily, total);

      }
    }while (interiorboxes!=-9999);

    total = inttotal + fortotal;

    printf("%10ld %10ld %10ld\n", inttotal, fortotal, total);
 return 0;
}

