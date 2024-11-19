#include <stdio.h>

int numWords(char* str)
{
	int numspace = 1;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			numspace++;
		}
	}
	return numspace;
}

int main()
{
	char str[] = "All the time you have to leave the space";

	printf("The number of words of this sentence is: %d", numWords(str));

	return 0;
}