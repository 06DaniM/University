#include <iostream>

using namespace std;

// Ex 1
float intercanvi_estatic(float& a, float& b) 
{
	float c = a;
	a = b;
	b = c;
	return a, b;
}

// Ex 3
int* assignatArray(const int longitud)
{
	int* temporal = new int[longitud]{};
	return temporal;
}

int main()
{
	// Ex 1
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

	// Ex 2	
	int x = 5;
	int* p = &x;
	x = x * *p;
	cout << p;

	// Ex 3
	const int longitud = 4;
	assignatArray(longitud);
	
	return 0;
}
