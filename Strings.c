#include <stdio.h>

void ex5()
{
	char dni[50];
	printf("Introduce your dni, but just the numbers: \n");
	scanf_s("%s",dni, 50);

	printf("%s", dni);
}

int main()
{
	ex5();
	return 0;
}
