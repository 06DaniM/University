#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min))  

void minesweeper(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    srand(time(NULL));

    int matrix[9][9];

    minesweeper(matrix);

    return 0;
}