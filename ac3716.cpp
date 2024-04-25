#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a;
bool islow(char x)
{
    return x >= 'a' && x <= 'z';
}
int main()
{
    while (cin >> a)
    {
        for (int i = 0, j = 0; i < a.size(); i++)
        {
            if (!islow(a[i]))
            {
                cout << '_';
                a[i] = a[i] - 'A' + 'a';
            }
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}