#include <stdio.h>

int contchar(char str[], char elem)
{
	int let = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == elem)
		{
			let++;
		}
	}
	return let;
}

int main()
{
	char str[] = "abcaadga";

	printf("%d\n", contchar(str, 'a'));

	return 0;
}