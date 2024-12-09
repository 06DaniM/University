/* ----------------------------------------------------------------------- */
/*                          INSERT YOUR NAME HERE                          */
/* ----------------------------------------------------------------------- */

#ifndef EX1_H
#define EX1_H

#include "checkTest.h"

// TO DO
// Insert your code here
// Insereix aquí el teu codi
// Inserta aquí tu código     

struct Player
{
    char* name;
    int health;
};

struct Action
{
    char* type;
    int value_action;
};

int updateHealth(struct Player p, struct Action act)
{

    // TO DO
    // Insert your code here
    // Insereix aquí el teu codi
    // Inserta aquí tu código     

    if (act.type == "potion")
    {
        p.health += act.value_action;
    }

    else if (act.type == "attack")
    {
        p.health -= act.value_action;
    }

    if (p.health > 100)
    {
        p.health = 100;
    }

    return p.health;
}


// DO NOT MODIFY THE CODE BELOW!!
// NO MODIFICAR EL CODI DEL TEST!!
// NO MODIFICAR EL CODIGO DEL TEST!!

void testEx1()
{

    struct Player p1 = { "Aaa", 75 };
    struct Action a1 = { "attack", 5 };
    struct Player p2 = { "Aaa", 10 };
    struct Action a2 = { "attack", 25 };
    struct Player p3 = { "Aaa", 75 };
    struct Action a3 = { "potion", 5 };
    struct Player p4 = { "Aaa", 90 };
    struct Action a4 = { "potion", 15 };
    struct Player p5 = { "Aaa", 21 };
    struct Action a5 = { "attack", 0 };
    struct Player p6 = { "Aaa", 21 };
    struct Action a6 = { "potion", 0 };
	struct Player p7 = { "Aaa", 21 };
    struct Action a7 = { "sleep", 10 };

    int res11 = updateHealth(p1, a1) ==  70;
    int res12 = updateHealth(p2, a2) == 0;
    int res13 = updateHealth(p3, a3) == 80;
    int res14 = updateHealth(p4, a4) == 100;
    int res15 = updateHealth(p5, a5) == 21;
    int res16 = updateHealth(p6, a6) == 21;
	int res17 = updateHealth(p7, a7) == 21;

    CHECK("Ex 1 - updateLife(...)",
        res11 == 1 &&
        res12 == 1 &&
        res13 == 1 &&
        res14 == 1 &&
        res15 == 1 &&
        res16 == 1 && 
		res17 == 1);
}

#endif // EX1_H
