#include <iostream>
using namespace std;

void misteri(int *array, int longitud) {
    for (int i = 0; i < longitud / 2; ++i) {
        int x = *(array + i);
        array[i] = array[longitud - 1 - i];
        array[longitud - 1 - i] = x;
    }
}
int main()
{
    int longitud = 5;
    int* array = (int*)calloc(longitud, sizeof(int));
    for (int i = 0; i < longitud; ++i) {
        array[i] = i + 1;
    }
    misteri(array, longitud);
    for (int i = 0; i < longitud; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int* sumarArrays(int arr1[], int long1, int arr2[], int long2) {
    // aqui el vostre codi

    int maxlong;

    if (long1 > long2) maxlong = long1;
    else maxlong = long2;

    int* arr = new int[maxlong];

    for (int i = 0; i < maxlong; i++)
    {
        arr[i] = arr1[i] + arr2[i];
    }
    return arr;
}

int main()
{
    int longitud1, longitud2;
    cout << "Introduce the lenght: ";
    cin >> longitud1 >> longitud2;
    // aqui el vostre codi;


    int maxlong;
    int *num = 0;

    if (longitud1 > longitud2) maxlong = longitud1;
    else maxlong = longitud2;
    
    int* arr1 = new int[longitud1];
    int* arr2 = new int[longitud2];

    cout << "Introduce the values of the first array";

    for (int i = 0; i < longitud1; ++i) 
    {
        cin >> (arr1[i]);
    }

    cout << "Introduce the values of the second array";

    for (int i = 0; i < longitud2; ++i)
    {
        cin >> (arr2[i]);
    }

    cout << "The final result is: ";

    for (int i = 0; i < maxlong; i++)
    {
        cout << sumarArrays(arr1, longitud1, arr2, longitud2)[i]<< " ";
    }
    

    return 0;
}
