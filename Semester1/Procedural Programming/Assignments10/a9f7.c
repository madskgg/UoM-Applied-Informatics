#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"

void DateString(int day, int month, int year, char date[10]);

int main()
{
    int day, month, year;
    char date[10];

    printf("Dwse thn hmera: ");
    day=GetInteger();
    printf("Dwse ton mhna: ");
    month=GetInteger();
    printf("Dwse to etos: ");
    year=GetInteger();

    DateString(day, month, year, date);
    printf("%s", date);

    return 0;
}

void DateString(int day, int month, int year, char date[10]) {
  char monthStr[10];

  switch (month) {
    case 1:
      strcpy(monthStr, "Jan");
      break;
    case 2:
      strcpy(monthStr, "Feb");
      break;
    case 3:
      strcpy(monthStr, "Mar");
      break;
    case 4:
      strcpy(monthStr, "Apr");
      break;
    case 5:
      strcpy(monthStr, "May");
      break;
    case 6:
      strcpy(monthStr, "Jun");
      break;
    case 7:
      strcpy(monthStr, "Jul");
      break;
    case 8:
      strcpy(monthStr, "Aug");
      break;
    case 9:
      strcpy(monthStr, "Sep");
      break;
    case 10:
      strcpy(monthStr, "Oct");
      break;
    case 11:
      strcpy(monthStr, "Nov");
      break;
    case 12:
      strcpy(monthStr, "Dec");
      break;
  }

  int i = 0;

  int dayLength = sprintf(&date[i], "%d", day);
  i += dayLength;

  date[i++] = '-';
  strcpy(&date[i], monthStr);
  i += 3;

  date[i++] = '-';
  sprintf(&date[i], "%02d", year % 100);
  i += 2;

  date[i] = '\0';
}
