#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int a[10];
string s;
int main()
{
    for (int i = 1; i <= 9; i++)
        cin >> a[i];
    cin >> s;
    for (auto x : s)
    {
        cout << a[x - '0'];
    }
    return 0;
}