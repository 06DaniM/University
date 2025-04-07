#include <iostream>
#include <vector>
using namespace std;

int min(vector<int>v1, int index)
{
	int min = v1[index];
	int pos = index;

	for (int i = index + 1; i < v1.size();i++)
	{
		if (v1[i] < min)
		{
			min = v1[i];
			pos = i;
		}
	}
	return pos;
}

void selectionSort(vector<int>& v1)
{
	for (int i = 0; i < v1.size() - 1; i++)
	{
		int num = min(v1, i);
		swap(v1[i], v1[num]);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
}

int main()
{
	vector <int>v1 = { 14 , 89, 33, 55, 44, 1 };

	selectionSort(v1);

	cout << endl;

	return 0;
}