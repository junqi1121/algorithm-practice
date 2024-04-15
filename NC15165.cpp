#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 10, M = 1e5 + 10;
int n, m;
string s;
int ne[N];
inline void solve()
{
    /* write your code here!! */
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 2; i <= n; i++)
    {
        int pre = ne[i - 1];
        while (pre && s[pre + 1] != s[i])
            pre = ne[pre];
        ne[i] = pre + (s[pre + 1] == s[i]);
    }
    if (!ne[n])
    {
        cout << "Just a legend" << endl;
        return;
    }
    for (int i = 2, j = 0; i <= n - 1; i++)
    {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        if (j == ne[n])
        {
            cout << s.substr(1, ne[n]) << endl;
            return;
        }
    }

    if (!ne[ne[n]])
    {
        cout << "Just a legend" << endl;
        return;
    }
    else
    {
        cout << s.substr(1, ne[ne[n]]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}