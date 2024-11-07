#include <stdio.h>

int sameVec(int vec1[], int size1,
			int vec2[], int size2)
{
	if (size1 != size2)
	{
		printf("They are not the same vectors");
		return 0;
	}

	for (int i = 0; i < size1; i++)
	{
		if (vec1[i] != vec2[i])
		{
			printf("They are not the same vectors");
			return 0;
		}
	}
	printf("They are the same vectors");
	return 1;
}

int main()
{
	int vec1[] = {3, 4, 5};
	int vec2[] = {3, 4, 5};
	int size1 = 3;
	int size2 = 3;
	sameVec(vec1, size1, vec2, size2);

	return 0;
}