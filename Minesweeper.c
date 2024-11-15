#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RANDOM_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min))  

void mat1(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void mat2(int matrix2[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%c ", matrix2[i][j]);
        }
        printf("\n");
    }
}

void minesweeper(int matrix[9][9])
{
    bool minesweeper = false;
    int coorX, coorY;
    int matrix2[9][9];
    int res;
    int mines = 10;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        int min = 0;
        int max = 8;

        int num1 = RANDOM_RANGE(min, max);
        int num2 = RANDOM_RANGE(min, max);

        if (matrix[num1][num2] == 0)
        {
            matrix[num1][num2] = 1;
        }

        else
            i--;
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matrix2[i][j] = '-';
        }
    }

    printf("Welcome to the minesweeper game, introduce coordenates (X and Y) where there is no mines, after you put the coordenate, you will be ask if you know where is a mine. Good luck\n");

    mat2(matrix2);
    printf("\n");
    mat1(matrix);

    while (minesweeper == false)
    {
        printf("Enter the X coordenate: ");
        scanf_s("%d", &coorX);

        printf("Enter the Y coordenate: ");
        scanf_s("%d", &coorY);

        if (matrix[coorY - 1][coorX - 1] == 0)
        {
            matrix2[coorY - 1][coorX - 1] = 'B';
            printf("There is no mine there.\n");
        }

        else if (matrix[coorY - 1][coorX - 1] == 1)
        {
            printf("There is a mine you lost.\n");
            mat1(matrix);
            minesweeper = true;
            break;
        }

        if ((matrix[coorY - 2][coorX - 2] == 1) || (matrix[coorY - 1][coorX - 2] == 1) || (matrix[coorY][coorX - 2] == 1) || (matrix[coorY - 2][coorX - 1] == 1) ||
            (matrix[coorY][coorX - 1] == 1) || (matrix[coorY - 2][coorX] == 1) || (matrix[coorY - 1][coorX] == 1) || (matrix[coorY][coorX] == 0))
        {
            printf("There is a mine near.\n");
        }
        mat2(matrix2);

        printf("Do you know where is a mine ?? 1/0\n");
        scanf_s("%d", &res);

        if (res == 1)
        {
            printf("Enter the X coordenate of the mine: \n");
            scanf_s("%d", &coorX);

            printf("Enter the Y coordenate of the mine: \n");
            scanf_s("%d", &coorY);

            if (matrix[coorY - 1][coorX - 1] == 1)
            {
                printf("You are correct.\n");
                matrix2[coorY - 1][coorX - 1] = 'M';
                mines--;
                if (mines == 0)
                {
                    printf("Congrats, you won!!");
                    minesweeper = true;
                }
                mat2(matrix2);
            }

            else
            {
                printf("There is no mine there, you lost.\n");
                mat1(matrix);
                minesweeper = true;
                break;
            }
        }
    }
}

int main()
{
    srand(time(NULL));

    int matrix[9][9];

    minesweeper(matrix);

    return 0;
}
