#include <iostream>;
using namespace std;
#include <vector>;

class Personatge
{
private:
	string name;
	int vida;
	int lvl;

	bool lvlUp() {
		cout << "lvl +1" << endl;
		return true;
	}

	bool curacion() {
		cout << "healed" << endl;
		return true;
	}

public:
	Personatge() { }

	Personatge(string name, int vida, int lvl) {
		this->name = name;
		this->vida = vida;
		this->lvl = lvl;
	}

	int checklvl(bool condition) {
		if (condition == true) {
			lvlUp();
		}
		this->lvl++;
		return this->lvl;
	}

	int potion(bool potion) {
		if (potion == true) {
			curacion();
		}
		this->vida = vida + 10;
		return this->vida;
	}

	string getName() { return this->name; }
	int getVida() { return this->vida; }
	int getLVL() { return this->lvl; }
};

class Mago {
public:
	string habilitat = "tonteria maxima";

	Mago() {}

	void HabilitatEspecial() {
		cout << "Executant " <<habilitat << endl;
	}

};

class Guerrer {
public:
	string habilitat = "tonteria minima";
	
	Guerrer() {}
	
	void HabilitatEspecial() {
		cout << "Executant " << habilitat << endl;
	}

};

class Arquer {
public:
	string habilitat = "tonteria parcial";


	Arquer() {}
	

	void HabilitatEspecial() {
		cout << "Llençant " << habilitat << endl;
	}
};

int main() {
	
	vector <Personatge> ps;
	//Creacion y Print de Personaje
	ps.push_back(Personatge("Bobo Adam", 120, 1));
	cout << "Name: " << ps[0].getName() << endl;
	cout << "Vida: " << ps[0].getVida() << endl;
	cout << "Nivel: " << ps[0].getLVL() << endl;

	//Actualizacion de datos privados
	cout << ps[0].checklvl(true) << endl;
	cout << ps[0].potion(true) << endl;
	//Comprovacion de Actualizacion
	cout << "Vida: " << ps[0].getVida() << endl;
	cout << "Nivel: " << ps[0].getLVL() << endl;
	Mago m;
	Guerrer g;
	Arquer a;

	m.HabilitatEspecial();
	g.HabilitatEspecial();
	a.HabilitatEspecial();

	return 0;
}
