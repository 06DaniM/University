#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

double distanciaEuclidiana(vector<int> punt1, vector<int> punt2)
{
	float distance = 0;
	for (int i = 0; i < punt1.size(); i++)
	{
		float res = 0;
		res = (punt1[i] - punt2[i]);
		res *= res;
		distance += res;
	}
	distance = sqrt(distance);
	return distance;
}

int main()
{
	vector<int> punt1 = { 2,5 };
	vector<int> punt2 = { 5,6 };

	cout << distanciaEuclidiana(punt1, punt2) << endl;

	return 0;
}