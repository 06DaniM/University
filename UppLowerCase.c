#include <stdio.h>

int main() 
{
    char ch;

    printf("Enter a letter: ");
    scanf_s(" %c", &ch); 

    if (ch >= 'A' && ch <= 'Z') 
    {
        ch = ch + ('a' - 'A');
    }

    else if (ch >= 'a' && ch <= 'z') 
    {
        ch = ch - ('a' - 'A');
    }

    else 
    {
        printf("Invalid input, please enter an alphabet letter.\n");
        return 1;
    }


    printf("Converted letter: %c\n", ch);

    return 0;
}
