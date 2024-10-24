/* ----------------------------------------------------------------------------------- */
/*     INSERT YOUR NAME HERE // INSEREIX EL TEU NOM AQU� // INSERTA AQU� TU NOMBRE     */
/* ----------------------------------------------------------------------------------- */

#ifndef EX3_H
#define EX3_H

#include "checkTest.h"

int numQuadrant(int x, int y)
{
    if (x == 0 || y == 0) {
        return -1; // El punto est� en el origen o en uno de los ejes
    }
    else if (x > 0 && y > 0) {
        return 1; // Primer cuadrante
    }
    else if (x < 0 && y > 0) {
        return 2; // Segundo cuadrante
    }
    else if (x < 0 && y < 0) {
        return 3; // Tercer cuadrante
    }
    else {
        return 4; // Cuarto cuadrante
    }
}




// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx3()
{
    CHECK("Ex 3 - numQuadrant(...)",
        numQuadrant(3, -2) == 4 &&
        numQuadrant(0, 6) == -1 &&
        numQuadrant(0, 0) == -1 &&
        numQuadrant(-2, -2) == 3 &&
        numQuadrant(-7, 0) == -1 &&
        numQuadrant(-2, 1) == 2 &&
        numQuadrant(1, 5) == 1
    );
}


#endif // EX3_H
