#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_RANGE(min, max) (rand() % ((max) - (min) + 1) + (min))

int main() {

    srand(time(NULL));

    int xmin = 0;
    int xmax = 4;

    int ymin = 0;
    int ymax = 4;

    int XrandomValue = RANDOM_RANGE(xmin, xmax);
    int YrandomValue = RANDOM_RANGE(ymin, ymax);

    printf("X = %d \nY = %d\n", XrandomValue, YrandomValue);

    int xplayer;
    int yplayer;

    char check; // Comprueba que no haya caracteres sobrantes

    printf("Introduce an integer number for the player in the X axis between 0 and 4: \n");

    if (scanf_s("%d%c", &xplayer, &check, 1) != 2 || check != '\n' || xplayer < 0 || xplayer > 4) 
    {
        printf("The number you introduced is not allowed (must be an integer between 0 and 4).\n");
        return 1;
    }

    printf("Introduce an integer number for the player in the Y axis between 0 and 4: \n");

    if (scanf_s("%d%c", &yplayer, &check, 1) != 2 || check != '\n' || yplayer < 0 || yplayer > 4) 
    {
        printf("The number you introduced is not allowed (must be an integer between 0 and 4).\n");
        return 1;
    }

    if (xplayer <= XrandomValue && yplayer <= YrandomValue) 
    {
        printf("The position of the player you introduced is inside the shelter, well done!\n");
    }

    else 
    {
        printf("The position of the player you introduced is outside the shelter, good luck next time!\n");
    }

    return 0;
}
