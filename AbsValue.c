#include <stdio.h>

int main()
{
	int num;
	
	printf("Introduce a number: ");
	scanf_s("%d", &num);
	
	if (num <= 0)
	{
		num *= -1;
	}

	printf("%d", num);

	return 0;
}
