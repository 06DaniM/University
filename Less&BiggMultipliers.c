#include <stdio.h>

void printFirstAndLastMultipleInRange(int val, int min, int max)
{
	int lowmulti = 0;
	int bigmulti = 0;

	while (min <= max)
	{
		if (min % val == 0)
		{
			if (lowmulti == 0)
			{
				lowmulti = min;
			}

			else
				bigmulti = min;
		}

		min++;
	}

	printf("The Lowest number that multiplies yours is: %d \nThe biggest is: %d", lowmulti, bigmulti);
}

int main()
{
	int val;
	int min;
	int max;

	printf("Introduce a number: \n");
	scanf_s("%d", &min);

	printf("Introduce a bigger number: \n");
	scanf_s("%d", &max);

	printf("Enter a number to see which numbers are the smallest and biggers multipliers: \n");
	scanf_s("%d", &val);

	printFirstAndLastMultipleInRange(val, min, max);

	return 0;
}