#include <stdio.h>

int main()
{
	int sec;

	printf("Give me a number of seconds and I will return the number of hours: ");
	scanf_s("%d", &sec);

	printf("%d", sec / 3600);
	return 0;
}
