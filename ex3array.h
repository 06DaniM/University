/* ----------------------------------------------------------------------------------- */
/*     INSERT YOUR NAME HERE // INSEREIX EL TEU NOM AQUÍ // INSERTA AQUÍ TU NOMBRE     */
/* ----------------------------------------------------------------------------------- */

#ifndef EX3_H
#define EX3_H

#include "checkTest.h"


void sumClosestZero(int arr[], int arr_size)
{

	// TO DO
	// Insert your code here
	// Insereix aquí el teu codi
	// Inserta aquí tu código     

	int num1 = arr[0];
	int num2 = arr[1];

	for (int i = 0; i < arr_size - 1; i++)
	{
		for (int j = i + 1; j < arr_size; j++)
		{
			if (arr[i] < 0)
			{
				if (arr[j] < 0 && arr[i] + arr[j] > num1 + num2)
				{
					num1 = arr[i];
					num2 = arr[j];
				}

				else if (arr[j] > 0)
				{
					if (arr[i] + arr[j] > 0)
					{
						if (arr[i] + arr[j] < num1 + num2)
						{
							num1 = arr[i];
							num2 = arr[j];
						}
					}

					else if (arr[i] + arr[j] < 0)
					{
						if (arr[i] + arr[j] > num1 + num2)
						{
							num1 = arr[i];
							num2 = arr[j];
						}
					}
				}
			}

			else
			{
				if (arr[j] > 0 && arr[i] + arr[j] < num1 + num2)
				{
					num1 = arr[i];
					num2 = arr[j];
				}

				else if (arr[j] < 0)
				{
					if (arr[i] + arr[j] > 0)
					{
						if (arr[i] + arr[j] < num1 + num2)
						{
							num1 = arr[i];
							num2 = arr[j];
						}
					}

					else if (arr[i] + arr[j] < 0)
					{
						if (arr[i] + arr[j] > num1 + num2)
						{
							num1 = arr[i];
							num2 = arr[j];
						}
					}
				}
			}
		}
	}
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
}


// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx3()
{
    
	int vec1[] = { 0, 0 };
	int vec2[] = { 1, 5, 4, 3, 2 };
	int vec3[] = { -4, 0, -77, 3, 10 };
	int vec4[] = { -9, -8, -9 };
	int vec5[] = { 10, -44, -33 };
	
	printf("\n- Ex 3 - sumClosestZero(...)\n");
	
	printf("-----------------\n* Array [0, 0]\n0 + 0 = 0\n-----------------\n");
	sumClosestZero(vec1, 2);
	printf("\n");

	printf("-----------------\n* Array [1, 5, 4, 3, 2]\n1 + 2 = 3\n-----------------\n");
	sumClosestZero(vec2, 5);
	printf("\n");

	printf("-----------------\n* Array [-4, 0, -77, 3, 10]\n-4 + 3 = -1\n-----------------\n");
	sumClosestZero(vec3, 5);
	printf("\n");

	printf("-----------------\n* Array [-9, -8, -9]\n-9 + -8 = -17\n-----------------\n");
	sumClosestZero(vec4, 3);
	printf("\n");

	printf("-----------------\n* Array [10, -44, -33]\n10 + -33 = -23\n-----------------\n");
	sumClosestZero(vec5, 3);
	printf("\n");

	

	
	
}

#endif // EX3_H
