/* ----------------------------------------------------------------------------------- */
/*     INSERT YOUR NAME HERE // INSEREIX EL TEU NOM AQUÍ // INSERTA AQUÍ TU NOMBRE     */
/* ----------------------------------------------------------------------------------- */

#ifndef EX1_H
#define EX1_H

#include "checkTest.h"

int firstMultiple(int value, int min_range, int max_range) 
{
	int num = 0;

	while (min_range <= max_range || num == 0)
	{
		if (min_range % value == 0 || num != 0)
		{
			return min_range;
			break;
		}
		else if (min_range == max_range && num == 0)
		{
			return -1;
			break;
		}
		min_range++;
	}
}



// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx1()
{
	int res21 = firstMultiple(5, 9, 19) == 10;
	int res22 = firstMultiple(1, 100, 200) == 100;
	int res23 = firstMultiple(3, 30, 30) == 30;
	int res24 = firstMultiple(10, 21, 29) == -1;
	int res25 = firstMultiple(21, 22, 42) == 42;
	int res26 = firstMultiple(8, 8, 9) == 8;

	CHECK("Ex 1 - firstMultiple",
		res21 == 1 &&
		res22 == 1 &&
		res23 == 1 &&
		res24 == 1 &&
		res25 == 1 &&
		res26 == 1);
}

#endif
