#include <iostream>
#include <vector>
using namespace std;

class Personatge
{
private:
    string name;

protected:
    int vida;
    int lvl;

public:
    Personatge(string name, int lvl, int vida)
    {
        this->name = name;
        this->lvl = lvl;
        this->vida = vida;
    }

    virtual void Curar() = 0;
};

class Mago : public Personatge
{
private:
    string habilidad = "Fireball";

protected:
    int HP;
    int mana;

public:
    Mago(string name, int lvl, int vida, int hp, int mana, string habilidad) :
        Personatge(name, lvl, vida)
    {
        this->HP = hp;
        this->mana = mana;

        cout << "Name: " << name << endl << "Lvl: " << lvl << endl << "Life: " << vida << endl << "Hability: " << habilidad << endl << "Mana: " << mana << endl;
    }

    void ModificarNivell(int newlevel)
    {
        this->lvl += newlevel;
        cout << "Current level is: " << lvl << endl;
    }

    void Curar() override
    {
        this->vida += 20;
        cout << "Current life is: " << vida << endl;
    }

    void HabilitatEspecial()
    {
        cout << "Using: " << habilidad << endl;
        mana--;
        cout << "Current mana is: " << mana << endl;
    }   

    void PrinInfo()
    {
        cout << "Lvl: " << lvl << endl << "Life: " << vida << endl;
    }
};

int main()
{
    int opt = 0;

    // === CREATE A CHARACTER === //
    Mago m("Nano", 33, 100, 100, 5, "R25");

    // Loop
    while (opt != 10)
    {
        cout << "Opt: ";
        cin >> opt;
        cout << endl;

        if (opt == 0) m.ModificarNivell(1);
        if (opt == 1) m.HabilitatEspecial();
        if (opt == 2) m.Curar();
        if (opt == 3) m.PrinInfo();
    }

    return 0;
}
