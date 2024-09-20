#include <stdio.h>

int main()
{
	int playerlife;

	printf("Enter your Player Life here (between 0 and 100): \n");
	scanf_s("%d", &playerlife);

	if ((playerlife > 100) || (playerlife < 0))
	{
		printf("Your Player Life is not valid, learn how to read.");
	}

	else if (playerlife == 100)
	{
		printf("Your Player Life is full, why are you here?? ");
	}

	else if (playerlife == 0)
	{
		printf("You are already dead XD");
	}

	else
	{
		float booflife = playerlife + (0.25 * playerlife);
		printf("You recieved a potion boost life of 25%, now your have: \n%f", booflife);
	}
	return 0;
}
