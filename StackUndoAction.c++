#include <iostream>
#include <stack>
using namespace std;

class PlayerActions
{
public:

	void PerformAction(const std::string& action)
	{
		actions.push(action);
		cout << "Performing: " << action << endl;
	}

	void UndoLastAction()
	{
		cout << "Undoing: " << actions.top() << endl;
		actions.pop();
	}

	void ShowHistory() const
	{
		stack<string>act = actions;
		for (int i = 0; i < actions.size(); i++)
		{
			cout << "Element " << i+1 << " is: " << act.top() << endl;
			act.pop();
		}
	}

private:
	stack<string> actions;

};

int main()
{
	PlayerActions pa;

	pa.PerformAction("Attack");
	cout << endl;

	pa.PerformAction("Jump");
	cout << endl;

	pa.PerformAction("Jump");
	cout << endl;

	pa.PerformAction("Grab");
	cout << endl;

	pa.ShowHistory();
	cout << endl;

	pa.UndoLastAction();
	cout << endl;

	pa.ShowHistory();

	return 0;
}