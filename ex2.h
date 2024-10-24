/* ----------------------------------------------------------------------------------- */
/*     INSERT YOUR NAME HERE // INSEREIX EL TEU NOM AQUÍ // INSERTA AQUÍ TU NOMBRE     */
/* ----------------------------------------------------------------------------------- */

#ifndef EX2_H
#define EX2_H

#include "checkTest.h"
#include <stdio.h>

void printDigitsReverseOrder(unsigned int num)
{
    while (num > 0) {
        printf("%d", num % 10);  
        num /= 10;
    }
}




// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx2()
{
    printf("- Ex 2 - printDigitsReverseOrder\n\n");

    printf("* Digits in reverse order of 678910:\n ");
    printDigitsReverseOrder(678910);
    printf("\n\n");

    printf("* Digits in reverse order of 7:\n ");
    printDigitsReverseOrder(7);
    printf("\n\n");

    printf("* Digits in reverse order of 999:\n ");
    printDigitsReverseOrder(999);
    printf("\n\n");

    printf("* Digits in reverse order of 12345:\n ");
    printDigitsReverseOrder(12345);
    printf("\n\n");

    printf("* Digits in reverse order of 21:\n ");
    printDigitsReverseOrder(21);
    printf("\n\n");

    printf("* Digits in reverse order of 1000:\n ");
    printDigitsReverseOrder(1000);
    printf("\n\n\n");
}


#endif
