#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min)) 

int main()
{
    srand(time(NULL));

    int xmin = 3;
    int xmax = 9;
    int ymin = xmin;

    int RandomValue = RANDOM_RANGE(xmin, xmax);
    int limit = RandomValue + xmin;

    printf("X & Y = %d\n", RandomValue);

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
    
    return 0;
}
