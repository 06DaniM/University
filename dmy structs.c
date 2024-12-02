#include <stdio.h>

struct Dates
{
	unsigned short day;
	unsigned short year;
	char month[12];
};

int main()
{
	struct Dates dates[12] = {
		{1, 2020, "January"},
		{2, 2020, "February"},
		{3, 2020, "March"},
		{4, 2020, "April"},
		{5, 2020, "May"},
		{6, 2020, "June"},
		{7, 2020, "July"},
		{8, 2020, "August"},
		{9, 2020, "September"},
		{10, 2020, "October"},
		{11, 2020, "November"},
		{12, 2020, "December"}
	};

	for (int i = 11; i >= 0; i--)
	{
		printf("%d/%s/%d\n", dates[i].day, dates[i].month, dates[i].year);
	}
	return 0;
}
