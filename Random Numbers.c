#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int randVal = rand() % 10; // If (int randVal = rand() & 10;) Random number with one digit between 0 - 10
	printf("%d \n", randVal);

	int randVal2 =  rand() % 21; // If (int randVal = rand() % 21;) Random number with one digit between 0 - 20
	printf("%d \n", randVal2);

	int randVal3 = (rand() % 20) - 10;; // If (int randVal = (rand() % 20 ) - 10;) Random number with one digit between 0 - 20
	printf("%d \n", randVal3);

	return 0;
}