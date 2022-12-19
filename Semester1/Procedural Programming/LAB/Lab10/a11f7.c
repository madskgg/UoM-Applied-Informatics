#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 100

void removeSpaces(char a[]);

int main()
{
    char mail[LENGTH], name[LENGTH], server[LENGTH];
    int i,j;

    gets(mail);
    removeSpaces(mail);

//Username
    i=0;
    while (mail[i]!='@') i++;
    strncpy(name, mail, i);
    name[i]='\0';
    printf("%s\n", name);
    printf("%d\n", strlen(name));

//Mail server
    j=0;
    while (i<=strlen(mail))
    {
        server[j]=mail[i+1];
        j++;
        i++;
    }
    printf("%s", server);

    return 0;
}

void removeSpaces(char a[])
{
    int i,j;
    int first, last;

    first = 0;
    last = strlen(a) - 1;

    while (isspace(a[first]))
        first++;
    while (isspace(a[last]))
        last--;

    j=0;
    for (i=first; i<= last; i++)
    {
        a[j]=a[i];
        j++;
    }
    a[j]='\0';

}
