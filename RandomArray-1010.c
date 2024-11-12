#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min))  

void randomMatrix(int matrix[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d", matrix[i]);
    }
}

int main()
{
    srand(time(NULL));

    int xmin = -10;
    int xmax = 10;

    int matrix[10] = { RANDOM_RANGE(xmin, xmax), RANDOM_RANGE(xmin, xmax), RANDOM_RANGE(xmin, xmax),  
                        RANDOM_RANGE(xmin, xmax),  RANDOM_RANGE(xmin, xmax),  RANDOM_RANGE(xmin, xmax),  
                        RANDOM_RANGE(xmin, xmax),  RANDOM_RANGE(xmin, xmax),  RANDOM_RANGE(xmin, xmax),  
                        RANDOM_RANGE(xmin, xmax), };
    
    randomMatrix(matrix);

    return 0;
}