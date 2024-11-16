#ifndef EX1_H
#define EX1_H

#include "checkTest.h"
#include <stdbool.h>

int length(char* str) 
{
	// TO DO: Insert your code here
	int len = 0;
    while (str[len]) 
    {
        len++;
    }
    return len;
}

int isSubstring(char* str1, char* str2)
{
	// TO DO: Insert your code here
	int len1 = length(str1);
	int len2 = length(str2);
	int i = 0;
	int j = 0;

	bool sub = true;

	if (len1 >= len2)
	{
		while (i <= len1)
		{
			if (str2[j] == '\0')
				break;

			else if (str1[i] != str2[j])
			{
				sub = false;
			}

			else
			{
				sub = true;
				j++;
			}
			i++;
		}
	}
	
	else return 0;

	if (sub == true)
		return 1;

	else return 0;
}

// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx1()
{
	char* str1 = "1a 2b 3c";
	char* str2 = "b ";
	char* str3 = "Luke I am your father";
	char* str4 = " ";
	char* str5 = "Luke";
	char* str6 = "ther";
	char* str7 = "Leee";

	CHECK("Ex1 - isSubstring",
		isSubstring(str1, str1) == 1 &&
		isSubstring(str1, str2) == 1 &&
		isSubstring(str2, str1) == 0 &&
		isSubstring(str3, str1) == 0 &&
		isSubstring(str3, str4) == 1 &&
		isSubstring(str3, str5) == 1 &&
		isSubstring(str5, str3) == 0 &&
		isSubstring(str3, str6) == 1 &&
		isSubstring(str6, str2) == 0 &&
		isSubstring(str3, str7) == 0
	);
}


#endif