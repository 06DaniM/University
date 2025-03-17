#include <iostream>
#include <vector>
using namespace std;

class Personatge
{
private:
    string name;
    int lvl;

protected:
    int vida;

public:
    Personatge(){}
    Personatge(string name, int lvl, int vida)
    {
        this->name = name;
        this->lvl = lvl;
        this->vida = vida;
    }
};

class Mago : public Personatge
{
private:
    int HP;
    int mana;
    string habilidad = "Fireball";

public:
	Mago():Personatge(){}
	Mago(string name, int lvl, int vida, int hp, int mana, string habilidad):
        Personatge(name, lvl, vida)
        {
            this->HP = hp;
            this->mana = mana;

            cout << "Name: " << name << endl << "Lvl: " << lvl << endl << "Life: " << vida << endl << "Hability: " << habilidad << endl << "Mana: " << mana << endl;
        }
};

int main() 
{
    Mago m("Nano", 33, 100, 100, 5, "R25");

    return 0;
}
