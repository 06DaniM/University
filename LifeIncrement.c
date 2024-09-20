#include <stdio.h>

int main()
{
	int playerlife;

	printf("Enter your Player Life here: \n");
	scanf_s("%d", &playerlife);

	float booflife = playerlife + (0.25 * playerlife);
	printf("You recieved a potion boost life of 25%, now your have: \n%f", booflife);

	return 0;
}