#include <stdio.h>

void printInReverseRange(int vec[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", vec[i]);
    }
}

int main()
{
    int vec[] = {1, 2, 3};
    int size = 3;
    printInReverseRange(vec, size);
    return 0;
}
