#include <stdio.h>

int main()
{
	int num1;
	int num2;

	printf("1st number: \n");
	scanf_s("%d", &num1);

	printf("2nd number: \n");
	scanf_s("%d", &num2);

	printf("The result of the sum is: \n%i",num1 + num2);

	return 0;
}