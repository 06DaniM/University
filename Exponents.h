/* ----------------------------------------------------------------------------------- */
/*     INSERT YOUR NAME HERE // INSEREIX EL TEU NOM AQUÍ // INSERTA AQUÍ TU NOMBRE     */
/* ----------------------------------------------------------------------------------- */

#ifndef EX2_H
#define EX2_H

#include "checkTest.h"

unsigned int pow(unsigned int base, unsigned int exponent)
{
	int res = base;
	
	while (exponent > 1)
	{
		res *= base;
		exponent--;
	}
	return res;
	
}



// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx2()
{
	int res31 = pow(2, 1) == 2;
	int res32 = pow(2, 0) == 1;
	int res33 = pow(3, 3) == 27;
	int res34 = pow(10, 2) == 100;
	int res35 = pow(1, 9) == 1;
	int res36 = pow(0, 2) == 0;

	CHECK("Ex 2 - pow",
		res31 == 1 &&
		res32 == 1 &&
		res33 == 1 &&
		res34 == 1 &&
		res35 == 1 &&
		res36 == 1);

}


#endif
