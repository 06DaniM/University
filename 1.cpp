#include <iostream>
#include <vector>
using namespace std;

class Building
{
public:
	Building(string name)
	{
		this->name;
	}

	string GetName()
	{
		return name;
	}

protected:
	string name;

private:

};

class WareHouse : public Building
{
public:
	WareHouse(string name, int wood, int rocks, int wheat) : Building(name)
	{
		this->name = name;
		this->wood = wood;
		this->rocks = rocks;
		this->wheat = wheat;
	}

	void PrintResources()
	{
		cout << "-- " << name << " --" << endl << "Wood: " << wood << endl << "Rocks: " << rocks << endl << "Wheat: " << wheat << endl << endl;
	}

private:
	int wood;
	int rocks;
	int wheat;
};

class House : public Building
{
public:
	House(string name, int floors, int inhabitants, int servants) : Building(name)
	{
		this->name = name;
		this->floors = floors;
		this->inhabitants = inhabitants;
		this->servants = servants;
	}

	void PrintHouse()
	{
		cout << "-- " << name << " --" << endl << "Num. floors: " << floors << endl << "Num. inhabitants: " << inhabitants << endl << "Num. servants: " << servants << endl << endl;
	}

private:
	int floors;
	int inhabitants;
	int servants;
};

class Temple : public Building
{
public:
	Temple(string name, string god, int priests) : Building(name)
	{
		this->name = name;
		this->god = god;
		this->priests = priests;
	}

	void PrintTemple()
	{
		cout << "-- " << name << " --" << endl << "God: " << god << endl << "Num. priests: " << priests << endl;
	}

private:
	string god;
	int priests;
};

int main()
{
	WareHouse w("East Warehouse", 10, 20, 30);
	House h("Agripa's House", 2, 5, 10);
	Temple t("Mercury's Temple", "Mercury", 3);

	std::cout << "Wharehouse name: " << w.GetName() << std::endl << std::endl;

	w.PrintResources();
	h.PrintHouse();
	t.PrintTemple();

    return 0;
}