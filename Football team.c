#include <stdio.h>

struct Player
{
	char* name;
	char* position;
	int number;
};

struct Team
{
	char* team;

	struct Player lineup[6];
};

int printByPosition(struct Player arr[], struct Player pos)
{
	struct Player lineup[6];

	for (int i = 0; i < 6; i++)
	{
		if (arr[i].position == pos.position)
		{
			printf("The name of that player is: %c \nThe number of the player is: %c \n", arr[i].name, arr[i].number);
		}
	}
}

int main()
{
	struct Player lineup[6] = {
		{"Alonso", "G", 33},
		{"Nano", "D", 14},
		{"Magic", "D", 4},
		{"Chili", "M", 55},
		{"CdT", "F", 50},
		{"IlMatador", "F", 99}
	};

	struct Player pos;
	pos.position = "G";

	printByPosition(lineup, pos);

	return 0;
}