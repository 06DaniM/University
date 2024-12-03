#include <stdio.h>
#include <stdbool.h>

struct Color
{
	unsigned short R;
	unsigned short G;
	unsigned short B;
	unsigned short A;
};

int ColorInArray(struct Color arr[], struct Color usercolor, bool userInArray)
{
	for (int i = 0; i <= 4; i++)
	{
		if (arr[i].R == usercolor.R && arr[i].G == usercolor.G && arr[i].B == usercolor.B && arr[i].A == usercolor.A)
		{
			userInArray = true;
			break;
		}

		else 
			userInArray = false;
	}

	if (userInArray == true)
	{
		printf("The color is in the array.");
		return 0;
	}

	else
	{
		printf("The color is not in the array.");
		return 1;
	}
}

int main()
{
	bool userInArray = false;

	struct Color color[5];

	color[0].R = 0;
	color[0].G = 0;
	color[0].B = 180;
	color[0].A = 230;

	color[1].R = 145;
	color[1].G = 0;
	color[1].B = 255;
	color[1].A = 0;

	color[2].R = 0;
	color[2].G = 255;
	color[2].B = 0;
	color[2].A = 0;

	color[3].R = 255;
	color[3].G = 255;
	color[3].B = 255;
	color[3].A = 255;

	color[4].R = 255;
	color[4].G = 0;
	color[4].B = 0;
	color[4].A = 0;

	struct Color usercolor;

	printf("Insert a variable for R: \n");
	scanf_s("%hu", &usercolor.R);

	printf("Insert a variable for G: \n");
	scanf_s("%hu", &usercolor.G);

	printf("Insert a variable for B: \n");
	scanf_s("%hu", &usercolor.B);

	printf("Insert a variable for A: \n");
	scanf_s("%hu", &usercolor.A);

	ColorInArray(color, usercolor, userInArray);
}
