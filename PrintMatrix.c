#include <stdio.h>

void printMatrix(int matrix1[3][3], int sizey, int sizex)
{
	for (int i = 0; i < sizey; i++)
	{
		for (int j = 0; j < sizex; j++)
		{
			printf("%d ", matrix1[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int matrix[2][3] = {{ 1, 2, 3 },
						{ 4,5,6 }};
	printMatrix(matrix, 2, 3);
	return 0;
}