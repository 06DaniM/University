#include <iostream>
using namespace std;

void recursive_reverse_words()
{
    string s;
    if (cin >> s)
    {
        recursive_reverse_words();
        cout << s << endl;
    }
}

int main()
{
    recursive_reverse_words();

    return 0;
}