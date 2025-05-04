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
    cout << "Input list of elements to be Sorted\n";
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

    ImprimeixJugadors(llistaJugadors);
    Ordena_Per_Punts(llistaJugadors);
    Ordena_Per_Nom(llistaJugadors);

    cout << "\nSorted list of elements is\n";
    for (int i = 0; i < 10; i++)
    {
        cout << llistaJugadors[i].name << "\t";
    }

    cout << "\n\nSorted list of elements is\n";
    for (int i = 0; i < 10; i++)
    {
        cout << llistaJugadors[i].score << "\t";
    }

    return 0;
}

void Ordena_Per_Nom(vector<Jugador>& llistaJugadors)
{
    string temp;
    for (int i = 0; i < 10; i++)
    {                                // Recorre desde el inicio hasta el final del array.
        for (int j = i + 1; j < 10; j++)       // Compara el elemento en la posición i con todos los elementos a su derecha (j = i+1 hasta el final).
        {
            if (llistaJugadors[j].name < llistaJugadors[i].name) {          // Si a[j] < a[i], se intercambian (es decir, si el número a la derecha es más chico, lo pone antes).
                temp = llistaJugadors[i].name;
                llistaJugadors[i].name = llistaJugadors[j].name;
                llistaJugadors[j].name = temp;
            }
        }
    }
}

void Ordena_Per_Punts(vector<Jugador>& llistaJugadors)
{
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {                                // Recorre desde el inicio hasta el final del array.
        for (int j = i + 1; j < 10; j++)       // Compara el elemento en la posición i con todos los elementos a su derecha (j = i+1 hasta el final).
        {
            if (llistaJugadors[j].score < llistaJugadors[i].score) {          // Si a[j] < a[i], se intercambian (es decir, si el número a la derecha es más chico, lo pone antes).
                temp = llistaJugadors[i].score;
                llistaJugadors[i].score = llistaJugadors[j].score;
                llistaJugadors[j].score = temp;
            }
        }
    }
}
