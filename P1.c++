#include <iostream>
#include <vector>
using namespace std;

class SimObject
{
private:
	string name;

protected:
	int price;
	string ReturnName() {
		return name;
	}

public:
	SimObject(string name, int price)
	{
		this->name = name;
		this->price = price;
	};
};

class Furniture : public SimObject
{
private:
	int comfort;
	string category;

public:
	Furniture(string name, int price, int comfort, int energy, int mood) :
		SimObject(name, price)
	{
		this->comfort = comfort;
		this->category = category;
	}
};

class Sim : public SimObject
{
private:
	int age, energy, mood;

public:
	Sim(string name, int price, int age, int energy, int mood) :
		SimObject(name, price)
	{
		this->age = age;
		this->energy = energy;
		this->mood = mood;
	}
};

class Adult : public Sim
{
private:
	string job;
	int salary;

public:
	Adult(string name, int price, int age, int energy, int mood, string job, int salary) :
		Sim(name, price, age, energy, mood)
	{
		this->job = job;
		this->salary = salary;

		cout << "Name: " << name << endl << "Price: " << price << endl << "Age: " << age << endl << "Energy: " << energy << endl << "Mood: " << mood << endl
			<< "Job: " << job << endl << "Salary: " << salary << endl;
	}
};

class Child : public Sim
{
private:
	int schoolGrade;
	string favouriteToy;

public:
	Child(string name, int price, int age, int energy, int mood, int schoolGrade, string favouriteToy) :
		Sim(name, price, age, energy, mood)
	{
		this->schoolGrade = schoolGrade;
		this->favouriteToy = favouriteToy;

		cout << "Name: " << name << endl << "Price: " << price << endl << "Age: " << age << endl << "Energy: " << energy << endl << "Mood: " << mood << endl
			<< "SchoolGrade: " << schoolGrade << endl << "FavouriteToy: " << favouriteToy << endl;
	}
};

int main() 
{
	Adult a("Luigi Bros", 1000000, 21, 5, 7, "Unemployed", 50);

	cout << endl;

	Child c("Super Luigi Bros Jr", 0, 1, 0, -100, 6, "Nothing, is crying");

    return 0;
}
