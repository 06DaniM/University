#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> vec = { 1,7,3,2,4,7,5,8,0 };
	int num2 = 0;
	int num3 = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == vec[8])
		{
			num2++;
			if (num2 > num3)
			{
				num3 = num2;
			}
		}
	}
	cout << num3-1 << endl;
	return 0;
}
