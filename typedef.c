#include <stdio.h>

typedef unsigned char uc;

int main()
{
	uc val1 = 10;
	uc val2 = 20;
	uc res = val1 + val2;

	printf("%d + %d = %d", val1, val2, res);

	return 0;
}