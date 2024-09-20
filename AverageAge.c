#include <stdio.h>

int main()
{
	int num1;
	int num2;
	float averageage;

	printf("Put here your age: \n");
	scanf_s("%d", &num1);

	printf("Put here your age: \n");
	scanf_s("%d", &num2);

	averageage = (num1 + num2) / 2.0; //Or: averageage = (float) (num1 + num2) / 2;

	printf("Your average age is: \n%f", averageage);
	return 0;
}