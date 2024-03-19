#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string a = "abcdefg";
vector<int> b(9, 3);
int main()
{
    cout << a << endl;
    int i = 0;
    for (auto &x : b)
    {
        x += i++;
        cout << x << ' ';
    }

    cout << a << endl;
    return 0;
}