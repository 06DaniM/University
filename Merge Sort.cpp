#include<iostream>  
#include <vector>
using namespace std;

struct Jugador
{
    string name;
    int score;
};

void merge_Name(vector<Jugador>&, int, int, int);
void merge_Score(vector<Jugador>&, int, int, int);
void merge_sort(vector<Jugador>&, int, int);

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

    ImprimeixJugadors(llistaJugadors);
    merge_sort(llistaJugadors, 0, 10 - 1);


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

void merge_sort(vector<Jugador>& llistaJugadors, int low, int high)
{
    int mid;
    if (low < high)
    {
        // Divide el array en dos mitades
        mid = (low + high) / 2;

        // Aplica merge_sort recursivamente a cada mitad
        merge_sort(llistaJugadors, low, mid);
        merge_sort(llistaJugadors, mid + 1, high);

        // Fusiona las mitades ordenadas
        merge_Name(llistaJugadors, low, high, mid);
        merge_Score(llistaJugadors, low, high, mid);
    }
}

// Merge sort 
void merge_Name(vector<Jugador>& llistaJugadors, int low, int high, int mid)
{
    int i, j, k; // c[] será el array temporal
    string c[50];

    i = low;       // Índice para la primera mitad
    k = low;       // Índice para el array temporal
    j = mid + 1;   // Índice para la segunda mitad

    // Compara elementos de ambas mitades y los coloca en orden en c[]
    while (i <= mid && j <= high)
    {
        if (llistaJugadors[i].name < llistaJugadors[j].name)
        {
            c[k] = llistaJugadors[i].name;
            k++;
            i++;
        }
        else
        {
            c[k] = llistaJugadors[j].name;
            k++;
            j++;
        }
    }

    // Si quedan elementos en la primera mitad, los copia a c[]
    while (i <= mid)
    {
        c[k] = llistaJugadors[i].name;
        k++;
        i++;
    }

    // Si quedan elementos en la segunda mitad, los copia a c[]
    while (j <= high)
    {
        c[k] = llistaJugadors[j].name;
        k++;
        j++;
    }

    // Copia el array temporal c[] al array original arr[]
    for (i = low; i < k; i++)
    {
        llistaJugadors[i].name = c[i];
    }
}

void merge_Score(vector<Jugador>& llistaJugadors, int low, int high, int mid)
{
    int i, j, k, c[50]; // c[] será el array temporal

    i = low;       // Índice para la primera mitad
    k = low;       // Índice para el array temporal
    j = mid + 1;   // Índice para la segunda mitad

    // Compara elementos de ambas mitades y los coloca en orden en c[]
    while (i <= mid && j <= high)
    {
        if (llistaJugadors[i].score < llistaJugadors[j].score)
        {
            c[k] = llistaJugadors[i].score;
            k++;
            i++;
        }
        else
        {
            c[k] = llistaJugadors[j].score;
            k++;
            j++;
        }
    }

    // Si quedan elementos en la primera mitad, los copia a c[]
    while (i <= mid)
    {
        c[k] = llistaJugadors[i].score;
        k++;
        i++;
    }

    // Si quedan elementos en la segunda mitad, los copia a c[]
    while (j <= high)
    {
        c[k] = llistaJugadors[j].score;
        k++;
        j++;
    }

    // Copia el array temporal c[] al array original arr[]
    for (i = low; i < k; i++)
    {
        llistaJugadors[i].score = c[i];
    }
}
