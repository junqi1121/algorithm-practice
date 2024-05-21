#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a;
int main()
{
    while (cin >> a)
    {
        for (auto &x : a)
        {
            if (!islower(x))
                cout << '_', x = x - 'A' + 'a';
            cout << x;
        }
        cout << endl;
    }
    return 0;
}