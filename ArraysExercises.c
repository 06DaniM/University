#include <stdio.h>
#include <string.h>

int sumElems(int vec[], int size)
{
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		num += vec[i];
	}
	printf("The sum of the vectors are: %d\n", num);
}

int findElem(int vec[], int size, int elem)
{
	for (int i = 0; i < size; ++i) {

		if (vec[i] == elem) {
			return 1;
		}
	}

	return 0;
}

int maxVec(int vec[], int size)
{
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		if (num < vec[i])
		{
			num = vec[i];
		}
	}
	printf("The biggest number is: %d\n", num);
}

int sameVec(int vec1[], int size1, int vec2[], int size2) 
{
	if (size1 != size2)
	{
		printf("They are not the same vectors\n");
		return 0;
	}

	for (int i = 0; i < size1; i++)
	{
		if (vec1[i] != vec2[i])
		{
			printf("They are not the same vectors\n");
			return 0;
		}
	}
	printf("They are the same vectors\n");
	return 1;
}

int minVec(int vec[], int size)
{
	int num = 10;
	for (int i = 0; i < size; i++)
	{
		if (num > vec[i])
		{
			num = vec[i];
		}
	}
	printf("The smallest number is: %d\n", num);
}


int lenghtString(char str[])
{
	int lennum = 0;

	while (str[lennum] != '\0')
	{
		lennum++;
	}
	printf("The number of characters are: %d\n", lennum);
}

void strlength(char str[])
{
	int length = strlen(str);
	printf("The number of characters are: %d\n", length);
}

void printInReverseOrder(int vec[], int size) 
{
	for (int i = size - 1; i >= 0; i--)
	{
		printf("%d ", vec[i]);
	}

	printf("\n");
}

void printArray(int vec[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%d ", vec[i]);
	}

	printf("\n");
}

// You can suppose both arrays have the same size
void swapArrays(int vec1[], int vec2[], int size) 
{
	int vec11[] = { 0,0,0 };
	printf("Vector 1 = ");
	
	for (int i = 0; i < size; i++)
	{
		vec11[i] = vec1[i];
		vec1[i] = vec2[i];
		printf("%d ", vec1[i]);

	}

	printf("\n");
	printf("Vector 2 = ");

	for (int j = 0; j < size; j++)
	{
		vec2[j] = vec11[j];

		printf("%d ", vec2[j]);
	}
}

int main()
{
	int arr1[5] = {1,2,3,4,5};

	int vec1[] = { 5, 2, 3 };
	int size1 = 3;
	
	int vec2[] = { 1, -20, 3 };
	int size2 = 3;

	int vec31[] = { 3, 4, 5 };
	int vec32[] = { 3, 4, 5 };
	int size31 = 3;
	int size32 = 3;

	char str[] = "Hola";

	int vec4[] = { 1, 2, 3 };
	int size4 = 3;

	int vec5[] = { 14, 33, 55, 1, 81 };
	int size5 = 5;

	int vec61[] = { 1,2,3 };
	int vec62[] = { 4,5,6 };
	int size6 = 3;

	int res = findElem(arr1, 5, 3);

	sumElems(vec1, size1);
	printf("\n");
	
	printf("%d\n", res); //1 = Y; 0 = N
	printf("\n");

	maxVec(vec2, size2);
	printf("\n");

	minVec(vec2, size2);
	printf("\n");

	sameVec(vec31, size31, vec32, size32);
	printf("\n");

	printInReverseOrder(vec4, size4);
	printf("\n");

	lenghtString(str);
	strlength(str);
	printf("\n");

	printArray(vec5, size5);
	printf("\n");

	swapArrays(vec61, vec62, size6);
	printf("\n");

	return 0;
}