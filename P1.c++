#include <iostream>
using namespace std;

int* combinarArraysOrdenats(int* arr1, int longitud1, int* arr2, int longitud2)
{
	int i = 0;
	int j = 0;
	int k = 0;

	int* arr = (int*)malloc((longitud1 + longitud2) * sizeof(int));

	while (i < longitud1 && j < longitud2)
	{
		if (arr1[i] < arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}

		else
		{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	for (int l = i; l < longitud1; l++)
	{
		arr[k] = arr1[l];
		k++;
	}

	for (int l = j; l < longitud2; l++)
	{
		arr[k] = arr2[l];
		k++;
	}
	return arr;
}

int main() {
	int arr1[] = { 1, 3, 5, 7, 9 };
	int arr2[] = { 2, 4, 6, 8, 10 };
	// busqueu la forma de saber la mida de l'array
	int longitud1 = sizeof(arr1) / 4;
	int longitud2 = sizeof(arr2) / 4;;

	int* resultat = combinarArraysOrdenats(arr1, longitud1, arr2, longitud2);

	cout << "L'array combinat ordenat és: ";
	for (int i = 0; i < longitud1 + longitud2; ++i) {
		cout << resultat[i] << " ";
	}
	cout << endl;

	// Alliberar la memòria de l'array resultat
	delete[] resultat;

	return 0;
}
