#include <iostream>
using namespace std;

int main()
{
    int* arr = (int*)malloc(4 * sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        arr[i] = i+1;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << *(arr + i) << endl;
    }

    free(arr);
    return 0;
}