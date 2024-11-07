#include <stdio.h>

int maxVec(int vec[], int size)
{
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        if (num < vec[i])
        {
            num = vec[i];
        }
    }
    printf("The biggest number is: %d", num);
}

int main()
{
    int vec[] = {1, 20, 3};
    int size = 3;

    maxVec(vec, size);

    return 0;
}
