#include <iostream>
#include <vector>

using namespace std;

struct String
{
	string name;
	int score;
	int minutes;
	int seconds;
};

int main()
{
	String str;

	int number_players_store;

	cout << "Enter the number of the players you want to store" << '\n';
	cin >> number_players_store;

	vector <String> primera(number_players_store);

	for (int i = 0; i < number_players_store; i++)
	{
		cout << "Enter the player name:" << '\n';
		cin >> primera[i].name;

		cout << "Enter the player score" << '\n';
		cin >> str.score;

		cout << "Enter the player minutes:" << '\n';
		cin >> str.minutes;

		cout << "Enter the player seconds" << '\n';
		cin >> str.seconds;
	}


	return 0;
}