#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min)) 

void exWithWhile(int xmin, int limit)
{
    int ymin = xmin; 

    while (ymin < limit)
    {
        if (xmin < limit)
        {
            printf("- ");
            xmin++;
        }
        else
        {
            printf("\n");
            xmin = 3;  
            ymin++;
        }
    }
}

void exWithFor(int xmin, int limit)
{
    for (int ymin = xmin; ymin < limit; ymin++)
    {
        for (int currentX = xmin; currentX < limit; currentX++)
        {
            printf("- ");
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    int xmin = 3;
    int xmax = 9;

    int randomValue = RANDOM_RANGE(xmin, xmax);
    int limit = randomValue + xmin;

    printf("X & Y = %d\n", randomValue);

    exWithFor(xmin, limit);
    printf("\n");
    exWithWhile(xmin, limit);

    return 0;
}
