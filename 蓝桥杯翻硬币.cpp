#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f3f
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 10, M = 1e3 + 10;
int n, m;
string a;
bool s[N], t[N];
inline void solve()
{
    /* write your code here!! */
    cin >> a;
    for (int i = 1; i <= a.size(); i++)
    {
        s[i] = a[i - 1] == '*' ? 0 : 1;
    }
    cin >> a;
    for (int i = 1; i <= a.size(); i++)
    {
        t[i] = a[i - 1] == '*' ? 0 : 1;
    }
    int ans = 0;
    for (int i = 1; i <= a.size(); i++)
    {
        // cout << s[i] << ' ' << t[i] << endl;
        if (s[i] != t[i])
        {
            s[i] = !s[i];
            s[i + 1] = !s[i + 1];
            ans++;
        }
    }
    cout << ans;
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