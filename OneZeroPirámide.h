/* ----------------------------------------------------------------------------------- */
/*     INSERT YOUR NAME HERE // INSEREIX EL TEU NOM AQUÍ // INSERTA AQUÍ TU NOMBRE     */
/* ----------------------------------------------------------------------------------- */

#ifndef EX1_H
#define EX1_H

#include "checkTest.h"

void onesZerosTriangle(unsigned int rows)
{

    // TO DO
    // Insert your code here
    // Insereix aquí el teu codi
    // Inserta aquí tu código
    
    int num = 1;
    int a = 0;
    int y = 0;
    
    while (y < rows)
    {
        if (a <= y)
        {
            if (num == 0)
            {
                printf("%d", num);
                num++;
                a++;
            }

            else
            {
                printf("%d", num);
                num--;
                a++;
            }
        }

        else
        {
            if (y % 2 == 0)
            {
                printf("\n");
                num = 0;
                a = 0;
                y++;
            }

            else
            {
                printf("\n");
                num = 1;
                a = 0;
                y++;
            }
        }
            
    }

    /*int num = 1;
    int a = 0;
    int y = 1;

    while (y <= rows)
    {
        if (a + 1 <= y)
        {
            printf("%d", (y + a) % 2);
            a++;
        }

        else
        {
            printf("\n");
            a = 0;
            y++;

        }

    }*/

    /*for (int i = 0; i <= rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d", (i + j) % 2);
        }
        printf("\n");
    }*/
}



// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx1()
{
    printf("- Ex 1 - OnesZerosTriangles \n\n");
    
    printf("* Triangle 5 rows:\n");
    onesZerosTriangle(5);
    printf("\n");

    printf("* Triangle 7 rows:\n");
    onesZerosTriangle(7);
    printf("\n");
    
    printf("* Triangle 1 row:\n");
    onesZerosTriangle(1);
    printf("\n\n\n");
    
}

#endif // EX1_H
