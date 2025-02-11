#include <iostream>
using namespace std;

int recursive_digits(int n)
{
    if (n <= 9) return 1;
    else return 1 + recursive_digits(n / 10);
}

int main()
{
    int num = 555555;

    cout << recursive_digits(num) << endl;

    return 0;
}
