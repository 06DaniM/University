#include <stdio.h>

void ex5()
{
	char ch;
	printf("Introduce a character: \n");
	scanf_s("%c", &ch);

	printf("%c", ch);
}

int main()
{
	ex5();
	return 0;
}
