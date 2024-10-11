#include <stdio.h>

void printRangeReverse(int min, int max)
{
    if (min == max || min > max)
    {
        printf("The numbers are not valids.\n");
    }

    else
    {
        while (max > min)
        {
            printf("%d, ", max);
            max--;
        }

        if (max == min)
        {
            printf("%d", max);
            max--;
        }
    }
}

int main() 
{
    int min, max;

    printf("Introduce a number: \n");
    scanf_s("%d", &min);

    printf("Introduce a bigger number: \n");
    scanf_s("%d", &max);

    printRangeReverse(min, max);
    return 0;
}
