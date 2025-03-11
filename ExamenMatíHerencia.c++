#include <iostream>
using namespace std;

class Personatge
{
private:
    string nom;
    int salut, nivel;

    void ModificarNivell()
    {
        nivel++;
    }

    void Curar()
    {
        salut++;
    }

public:
    string habilitat;

    void HabilitatEspecial(string habilitat)
    {
        cout << habilitat;
    }
};

class Mago
{
public:
    Mago(Personatge& personatge)
    {
        personatge.habilitat = "Fire";
    }

    void Mago_Ability(Personatge& personatge)
    {
        cout << personatge.habilitat;
    }
};

class Guerrero
{
public:
    Guerrero(Personatge& personatge)
    {
        personatge.habilitat = "Sword";
    }
    void Guerrero_Ability(Personatge& personatge)
    {
        cout << personatge.habilitat;
    }
};

class Arquers
{
public:
    Arquers(Personatge& personatge)
    {
        personatge.habilitat = "Arrow";
    }
    void Arquers_Ability(Personatge& personatge)
    {
        cout << personatge.habilitat;
    }
};

int main() 
{
    

    return 0;
}
