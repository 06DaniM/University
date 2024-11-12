#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min))  

void randomMatrix(int matrix[])
{
    int num = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        printf("%d", matrix[i]);
        num = matrix[i];
        sum += num;
    }
    printf("Sum = %d", sum);
}

int main()
{
    srand(time(NULL));

    int xmin = 0;
    int xmax = 9;

    int matrix[6] = { RANDOM_RANGE(xmin, xmax), RANDOM_RANGE(xmin, xmax), RANDOM_RANGE(xmin, xmax),  
                        RANDOM_RANGE(xmin, xmax),  RANDOM_RANGE(xmin, xmax),  RANDOM_RANGE(xmin, xmax)};
    
    randomMatrix(matrix);

    return 0;
}