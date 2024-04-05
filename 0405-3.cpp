#include <iostream>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 10;
int n, m;
int a[N];
void solve()
{
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        if (s == "1")
            puts("2");
        else
            puts("1");
        return;
    }
    int num = 0;
    for (int i = 0; i <= s.size() - 2; i++)
    {
        if (s[i] == '0')
            s[i] = 1;
        else
            s[i] = 0;
        num = num * 10 + s[i];
    }

    if (num == 0)
    {
        if (s[s.size() - 1] == '1')
            num = 2;
        else
            num = 1;
    }
    else
    {
        if (s[s.size() - 1] == '0')
            num = num * 10 + 1;
        else
            num = num * 10;
    }

    cout << num << endl;
}
int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}