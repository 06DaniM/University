#include <stdio.h>

void ex1()
{
	int sec;

	printf("Give me a number of seconds and I will return the number of hours: ");
	scanf_s("%d", &sec);

	printf("%f",(float) sec / 3600);
}

int main()
{
	//ex1();

	char c1, c2;

	printf("Introduce one char: \n");
	scanf_s("%c", &c1);

	getchar();

	printf("Introduce another char: \n");
	scanf_s("%c", &c2);

	printf("c1 = %c \nc2 = %c", c1, c2);

	return 0;
}
