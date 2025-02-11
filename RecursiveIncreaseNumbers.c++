#include <iostream>
using namespace std;

bool recursive_increse_numbers(int n)
{
    if (n < 10) return true;
    if (n % 10 < (n / 10) % 10) return false;
    return recursive_increse_numbers(n / 10);
}

int main()
{
    cout << recursive_increse_numbers(4568) << endl;

    return 0;
}
