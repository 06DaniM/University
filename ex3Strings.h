#ifndef EX3_H
#define EX3_H

#include "checkTest.h"
#include <string.h>
#include <stdbool.h>

int isPalindrome(const char* str)
{
    int len = 0;
    int k = 0;
    bool letter = true;

    // TO DO: Insert your code here
    for (int i = 0; str[i] != '\0'; i++)
    {
        len = i;
    }

    for (int j = len; str[j] > len; j--)
    {
        if (str[j] == str[k])
            letter = true;
        else
        {
            letter = false;
            break;
        }
        k++;
    }

    if (letter == true)
        return 1;
    else
        return 0;
}



// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx3()
{
    CHECK("Ex3 - isPalindrome",
        isPalindrome("a") == 1 &&
        isPalindrome("ab") == 0 &&
        isPalindrome("abba") == 1 &&
        isPalindrome("anna") == 1 &&
        isPalindrome("hello") == 0 &&
        isPalindrome("world") == 0 &&
        isPalindrome("zipiz") == 1 &&
        isPalindrome("zippiz") == 1 &&
        isPalindrome("zippz") == 0);
}

#endif
