#include<iostream>  
#include <vector>
using namespace std;

struct Jugador
{
    string name;
    int score;
};

void Ordena_Per_Nom(vector<Jugador>&);
void Ordena_Per_Punts(vector<Jugador>&);

static void ImprimeixJugadors (vector<Jugador>& llistaJugadors)
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
    //{ 11, 5, 2, 20, 42, 53, 23, 34, 101, 22 };

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

    Ordena_Per_Nom(llistaJugadors);
    Ordena_Per_Punts(llistaJugadors);

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

void Ordena_Per_Nom(vector<Jugador>& llistaJugadors)
{
    for (int k = 1; k < 10; k++)
    {
        string temp = llistaJugadors[k].name;  // Se guarda el valor actual a insertar
        int j = k - 1;              // Se empieza a comparar con los elementos anteriores

        while (j >= 0 && temp <= llistaJugadors[j].name)
        {
            llistaJugadors[j + 1].name = llistaJugadors[j].name;   // Se corre el elemento hacia la derecha
            j = j - 1;                     // Se sigue comparando hacia la izquierda
        }

        llistaJugadors[j + 1].name = temp;  // Se coloca el valor en su posición correcta
    }
}

void Ordena_Per_Punts(vector<Jugador>& llistaJugadors)
{
    for (int k = 1; k < 10; k++)
    {
        int temp = llistaJugadors[k].score;  // Se guarda el valor actual a insertar
        int j = k - 1;              // Se empieza a comparar con los elementos anteriores

        while (j >= 0 && temp <= llistaJugadors[j].score)
        {
            llistaJugadors[j + 1].score = llistaJugadors[j].score;   // Se corre el elemento hacia la derecha
            j = j - 1;                     // Se sigue comparando hacia la izquierda
        }

        llistaJugadors[j + 1].score = temp;  // Se coloca el valor en su posición correcta
    }
}
