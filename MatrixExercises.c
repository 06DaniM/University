#include <stdio.h>

int findInMat(char mat[3][3], int rows, int cols)
{
	int elem1 = 'a';
	int elem2 = 'w';
	int num1 = 0;
	int num2 = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (mat[i][j] == elem1)
			{
				num1 = elem1;
			}

			else if (mat[i][j] == elem2)
			{
				num2 = elem2;
			}
		}
	}

	if(num1 != 0)
		printf("The element %c is in the matrix.\n", num1);

	else if (num2 != 0)
		printf("The element %c is in the matrix.\n", num2);

	else if ((num1 == 0) && (num2 == 0))
		printf("No element is in the matrix.\n");
}

int maxMat(int mat[4][3], int rows, int cols)
{
	int num = mat[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (mat[i][j] > num)
			{
				num = mat[i][j];
			}
		}
	}
	printf("%d\n", num);
}

int minMat(int mat[4][3], int rows, int cols)
{
	int num = mat[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (mat[i][j] < num)
			{
				num = mat[i][j];
			}
		}
	}
	printf("%d\n", num);
}

int printMat4x3(int mat[4][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int mat4x3[4][3] = { {1, 4, 88},
						 {55, -3, 0},
						 {12, -34, -56},
						 {1, 2, 3} };

	char mat3x3[3][3] = { {'c', 's', 'i' },
						  {'a', 'b', 'c' },
						  {':', '/', '#' } };

	findInMat(mat3x3, 3, 3);
	maxMat(mat4x3, 4, 3);
	minMat(mat4x3, 4, 3);
	printMat4x3(mat4x3, 4, 3);

	return 0;
}
