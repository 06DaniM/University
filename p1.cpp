#include <iostream>
using namespace std;

void sum(int val1, int val2, int* result)
{
    *result = val1 + val2;
}

int main()
{
    int val1, val2;

    cout << "Insert values to val1 and val2: \n";
    cin >> val1 >> val2;
    
    cout << endl;

    int result = 0;

    sum(val1, val2, &result);
    cout << "The result of the sum is: " << result << endl;


    return 0;
}