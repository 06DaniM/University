#include <stdio.h> 

void segZeroOne(int arr1[], int size_arr)
{
	int num0 = 0;
	int num1 = 0;

	for (int i = 0; i < size_arr; i++)
	{
		if (arr1[i] == 0)
		{
			num0++;
		}

		else if (arr1[i] == 1)
			num1++;
	}

	for (int j = 0; j < num0; j++)
	{
		printf("0");
	}

	for (int k = 0; k < num1; k++)
	{
		printf("1");
	}

	/*for (int i = 0; i < size_arr; i++)
	{
		if (arr1[i] == 0)
		{
			num0++;
		}
	}

	for (int j = 0; j < num0; j++)
	{
		printf("0");
	}

	for (int j = num0; j < size_arr; j++)
	{
		printf("1");
	}*/
}

int main()
{
	int arr[] = { 1,0,1,0,0,1,0,0,0,0,0 };
	int size = 10;
	segZeroOne(arr, size);

	return 0;
}