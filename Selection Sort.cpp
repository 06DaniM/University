#include<iostream>  
#include <vector>
using namespace std;

struct Jugador
{
    string name;
    int score;
};

int Ordena_Per_Nom(vector<Jugador>, int);
int Ordena_Per_Punts(vector<Jugador>, int);

static void ImprimeixJugadors (vector<Jugador> llistaJugadors)
{
    cout << "\nInput list of elements to be Sorted\n";
    for (int i = 0; i < 10; i++)
    {
        cout << llistaJugadors[i].name << ": " << llistaJugadors[i].score << "\n";
    }
}

int main()
{
    vector<Jugador> llistaJugadors (10);

    llistaJugadors[0] = { "Anna", 11 };
    llistaJugadors[1] = { "Marc", 5 };
    llistaJugadors[2] = { "Lia", 2 };
    llistaJugadors[3] = { "Pau", 20 };
    llistaJugadors[4] = { "Joan", 42 };
    llistaJugadors[5] = { "Clara", 53 };
    llistaJugadors[6] = { "Alex", 23 };
    llistaJugadors[7] = { "Sara", 34 };
    llistaJugadors[8] = { "Leo", 101 };
    llistaJugadors[9] = { "Eva", 22 };


    int pos, tempint, pass = 0;
    string tempstr;

    ImprimeixJugadors(llistaJugadors);

    for (int i = 0; i < 10; i++)
    {
        pos = Ordena_Per_Nom(llistaJugadors, i);        // Encuentra el �ndice del elemento m�s peque�o desde i hasta el final.
        tempstr = llistaJugadors[i].name;                     // Guarda temporalmente el valor actual en la posici�n i.
        llistaJugadors[i].name = llistaJugadors[pos].name;             // Coloca el m�s peque�o en la posici�n i.
        llistaJugadors[pos].name = tempstr;                   // Coloca el valor original de i en la posici�n donde estaba el m�s peque�o.
        pass++;                                // Cuenta el paso de ordenamiento.
    }

    for (int i = 0; i < 10; i++)
    {
        pos = Ordena_Per_Punts(llistaJugadors, i);        // Encuentra el �ndice del elemento m�s peque�o desde i hasta el final.
        tempint = llistaJugadors[i].score;                     // Guarda temporalmente el valor actual en la posici�n i.
        llistaJugadors[i].score = llistaJugadors[pos].score;             // Coloca el m�s peque�o en la posici�n i.
        llistaJugadors[pos].score = tempint;                   // Coloca el valor original de i en la posici�n donde estaba el m�s peque�o.
        pass++;                                // Cuenta el paso de ordenamiento.
    }

    cout << "\nSorted list of elements is\n";
    for (int i = 0; i < 10; i++)
    {
        cout << llistaJugadors[i].name << "\t";
    }

    cout << "\nSorted list of elements is\n";
    for (int i = 0; i < 10; i++)
    {
        cout << llistaJugadors[i].score << "\t";
    }

    return 0;
}

int Ordena_Per_Nom(vector<Jugador> llistaJugadors, int i)
{
    string ele_small;
    int position, j;

    ele_small = llistaJugadors[i].name;   // Inicializa el m�s peque�o como el primero del subarreglo
    position = i;
    for (j = i + 1; j < 10; j++)       // Recorre el resto del arreglo
    {
        if (llistaJugadors[j].name < ele_small)  // Si encuentra uno m�s peque�o
        {
            ele_small = llistaJugadors[j].name;
            position = j;
        }
    }
    return position;          // Devuelve la posici�n del menor valor
}

int Ordena_Per_Punts(vector<Jugador> llistaJugadors, int i)
{
    int ele_small, position, j;
    ele_small = llistaJugadors[i].score;   // Inicializa el m�s peque�o como el primero del subarreglo
    position = i;
    for (j = i + 1; j < 10; j++)       // Recorre el resto del arreglo
    {
        if (llistaJugadors[j].score < ele_small)  // Si encuentra uno m�s peque�o
        {
            ele_small = llistaJugadors[j].score;
            position = j;
        }
    }
    return position;          // Devuelve la posici�n del menor valor
}
