/* ----------------------------------------------------------------------------------- */
/*     INSERT YOUR NAME HERE // INSEREIX EL TEU NOM AQUÍ // INSERTA AQUÍ TU NOMBRE     */
/* ----------------------------------------------------------------------------------- */

#ifndef EX2_H
#define EX2_H

#include "checkTest.h"


void transpose(int mat[5][5]) 
{
    int mat1[5][5];
    // TO DO
    // Insert your code here
    // Insereix aquí el teu codi
    // Inserta aquí tu código     

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mat1[i][j] = mat[j][i];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mat[i][j] = mat1[i][j];
        }
    }

    return mat; 
}


// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx2()
{
    int mat[5][5] = { {1, 2, 3, 4, 5},
                      {6, 7, 8, 9, 10},
                      {11, 12, 13, 14, 15},
                      {16, 17, 18, 19, 20},
                      {21, 22, 23, 24, 25} };
   
    transpose(mat);

    int res = 
        mat[0][0] == 1 && mat[0][1] == 6 && mat[0][2] == 11 && mat[0][3] == 16 && mat[0][4] == 21 &&
        mat[1][0] == 2 && mat[1][1] == 7 && mat[1][2] == 12 && mat[1][3] == 17 && mat[1][4] == 22 &&
        mat[2][0] == 3 && mat[2][1] == 8 && mat[2][2] == 13 && mat[2][3] == 18 && mat[2][4] == 23 &&
        mat[3][0] == 4 && mat[3][1] == 9 && mat[3][2] == 14 && mat[3][3] == 19 && mat[3][4] == 24 &&
        mat[4][0] == 5 && mat[4][1] == 10 && mat[4][2] == 15 && mat[4][3] == 20 && mat[4][4] == 25;

   

    CHECK("Ex 2 - transpose(...)", res == 1);
        
}


#endif
