#include <stdio.h>

int isInRange(int num, int min, int max)
{
	if (num >= min && num <= max)
	{
		printf("Number is in range [%d, %d]", min, max);
	}

	else
		printf("Number is not in range [%d, %d]", min, max);
}

int main()
{
	int num, min, max;
	printf("Introduce a number: \n");
	scanf_s("%d", &num);
	
	printf("Introduce the minimum number: \n");
	scanf_s("%d", &min);
	
	printf("Introduce the maximum number: \n");
	scanf_s("%d", &max);

	isInRange(num, min, max);

	return 0;
}