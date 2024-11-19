#include <stdio.h>

int countTypeNums(int vec[], int sizeVec, char* type)
{
	int num = 0;
	int cont;

	if (type == "even") cont = 0;
	else cont = 1;

	for (int i = 0; i < sizeVec; i++)
	{
		if (vec[i] % 2 == cont) num++;
	}
	return num;
}

int countTypeNumsMat(int mat[2][3], int rows, int cols, char* type)
{
	int num = 0;
	int cont;

	if (type == "even") cont = 0;
	else cont = 1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (mat[i][j] % 2 == cont)
				num++;
		}
	}
	return num;
}

int main()
{
	int vec[] = { 33, 91, 75, 47, 2 };

	printf("Even: %d\n", countTypeNums(vec, 5, "even"));
	printf("Odd: %d\n", countTypeNums(vec, 5, "odd"));
	
	int mat[2][3] = {{33, 91, 75},
					{47, 2, 4} };

	printf("Even in matrix %d\n", countTypeNumsMat(mat, 2, 3, "even"));
	printf("Odd in matrix %d\n", countTypeNumsMat(mat, 2, 3, "odd"));

	return 0;
}