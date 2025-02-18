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
	return 0;
}
