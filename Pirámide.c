#include <stdio.h>

int main()
{
	int maxfiles;
	int currentfile = 1;
	int numberperfile = 1;

	printf("Introduce the number of files: \n");
	scanf_s("%d", &maxfiles);

	while (maxfiles >= currentfile)
	{
		printf("\n");
		while (numberperfile <= currentfile)
		{
			printf("%d ", numberperfile);
			numberperfile++;
		}

		if (numberperfile > currentfile)
		{
			currentfile++;
			numberperfile = 1;
		}
	}

	return 0;
}