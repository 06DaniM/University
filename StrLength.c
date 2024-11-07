#include <stdio.h>
#include <string.h>

int lenghtString(char str[])
{
    int lennum = 0;

    while (str[lennum] != '\0')
    {
        lennum++;
    }
    printf("The number of characters are: %d\n", lennum);
}

void strlength(char str[])
{
    int length = strlen(str);
    printf("The number of characters are: %d\n", length);
}

int main()
{
    char str[] = "Hola";

    lenghtString(str);
    strlength(str);

    return 0;
}
