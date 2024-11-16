#ifndef EX2_H
#define EX2_H

#include "checkTest.h"

int charsLongestWord(char str[]) 
{
    int i = 0;
    int j = 0;
    int num = 0;
    // TO DO: Insert your code here
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            j++;
        }

        else
            j = 0;

        if (num < j)
            num = j;
        i++;
    }
    return num;
}


void testEx2()
{
    char str1[] = "My name is Guybrush Threepwood and I want to be a pirate";
    char str2[] = "Luke I am your father";
    char str3[] = "I love the smell of napalm in the morning";
    char str4[] = "Frankly my dear I do not give a damn";
    char str5[] = "Houston we have a problem";
    char str6[] = "Hasta la vista baby";
    char str7[] = "Supercalifragilisticexpialidocious";
    char str8[] = "1";
    char str9[] = "1 a 2 b";
    char str10[] = "1a 2b 3c";
        
    
    CHECK("Ex2 - charsLongestWord(...)",
        charsLongestWord(str1) == 10 &&
        charsLongestWord(str2) == 6 &&
        charsLongestWord(str3) == 7 &&
        charsLongestWord(str4) == 7 &&
        charsLongestWord(str5) == 7 &&
        charsLongestWord(str6) == 5 &&
        charsLongestWord(str7) == 34 &&
        charsLongestWord(str8) == 1 &&
        charsLongestWord(str9) == 1 &&
        charsLongestWord(str10) == 2);

}


#endif
