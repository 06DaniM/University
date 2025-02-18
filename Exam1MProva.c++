#include <iostream>
using namespace std;

float intercanvi_estatic(float& a, float& b) 
{
	float c = a;
	a = b;
	b = c;
	return a, b;
}

int main()
{
	// ex 1
	float primera{ 222.0 };
	float segona{ 333.0 };
	float tercera;
	float quarta;
	tercera = intercanvi_estatic(segona, primera);
	cout << primera << '\n';
	cout << segona << '\n';
	cout << tercera << '\n';
	quarta = primera + segona;
	
	cout << quarta << endl;

	// ex2	
	int x = 5;
	int* p = &x;
	x = x * *p;
	cout << p;
	
	return 0;
}
