#include <stdio.h>

void findMinSumPair(int arr1[], int arr_size)
{
	int num1 = arr1[0];
	int num2 = arr1[1];
	int i = 0;
	int res;

	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			if (j == i)
			{
				j++;
			}
			
			if (arr1[i] + arr1[j] >= 0)
			{
				if (num1 + num2 > 0 && arr1[i] + arr1[j] < num1 + num2)
				{
					num1 = arr1[i];
					num2 = arr1[j];
				}

				else if (num1 + num2 < 0 && arr1[i] + arr1[j] < -(num1 + num2))
				{
					num1 = arr1[i];
					num2 = arr1[j];
				}
			}

			else if (arr1[i] + arr1[j] <= 0)
			{
				if (num1 + num2 < 0 && arr1[i] + arr1[j] > num1 + num2)
				{
					num1 = arr1[i];
					num2 = arr1[j];
				}

				else if (num1 + num2 > 0 && arr1[i] + arr1[j] > -(num1 + num2))
				{
					num1 = arr1[i];
					num2 = arr1[j];
				}
			}
		}
	}
	res = num1 + num2;
	printf("The sum of %d + %d, is closest to zero: %d", num1, num2, res);
}

int main()
{
	int arr1[] = { 33, -14, 1, 2, 1, 34, -25 };
	
	findMinSumPair(arr1, 7);

	return 0;
}