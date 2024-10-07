#include <stdio.h>

int main()
{
	float wight;
	float height;

	printf("Introduce the wight of the room: \n");
	scanf_s("%f", &wight);

	printf("Introduce the height of the room: \n");
	scanf_s("%f", &height);

	printf("The dimensions of the room are: \n%.2fm2", wight * height);
	return 0;
}