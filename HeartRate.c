#include <stdio.h>

int main()
{
	int age;

	printf("Put here your age: \n");
	scanf_s("%d", &age);

	float maximumheartrate = (float) (220 - age) / 10;

	printf("Your maximum heart rate is: \n%f", maximumheartrate);
}